#include <iostream>
#include <string>
#include <memory>
#include "dictionary.h"
#include "error.h"
#include "parser.h"
#include "CSVreporter.h"
#include "XMLreporter.h"
#include "cmdline.h"
#include "settings.h"

using namespace std;

Reporter * MakeReporter( Settings::Report rt ) {
	if ( rt == Settings::rtCSV ) {
		return new CSVReporter( cout );
	}
	else {
		return new XMLReporter( cout );
	}
}

void CheckSubmission( const Dictionary & d, istream & sub,
						const std::string & subname, Reporter & rep ) {
	Parser p( sub );
    string word;
	rep.ReportHeader();
	while( ( word = p.NextWord() ) != "" ) {
		if ( ! d.Check( word ) ) {
			rep.ReportError( word, p.Context(), p.LineNo(), subname );
		}
	}
	rep.ReportFooter();
}

int main( int argc, char * argv[] ) {

    try {

		CmdLine cl( argc, argv );
		Settings s( cl );
        Dictionary d( s.DictName() );
		auto_ptr <Reporter> rep( MakeReporter( s.ReportType() ) );

		if ( cl.Argc() == 1 ) {
			CheckSubmission( d, cin, "<stdin>", *rep );
		}
		else {
			for ( int i = 1; i < cl.Argc(); i++ ) {
				ifstream sub( cl.Argv(i).c_str() );
				if ( ! sub.is_open() ) {
					throw ScheckError( "Cannot open file " + cl.Argv(i) );
				}
				CheckSubmission( d, sub, cl.Argv(i), *rep );
			}
		}
    }
    catch( const ScheckError & e ) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    catch( ... ) {
        cerr << "Error: unknown exception" << endl;
        return 2;
    }
}
