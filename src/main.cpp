#include <iostream>
#include <string>
#include "dictionary.h"
#include "error.h"
#include "parser.h"
#include "reporter.h"
#include "XMLreporter.h"
#include "CSVreporter.h"

using namespace std;

int main( int argc, char * argv[] ) {
    try {
        cout << "scheck version 0.6" << endl;
        Dictionary d( "data/mydict.dat" );
        const char * subtext = "data/sub2.txt";
        ifstream sub( subtext );
        if ( ! sub.is_open() ) {
            throw ScheckError( string("cannot open data/sub1.txt") + subtext );
        }

        Parser p( sub );
        Reporter * rep = 0;
        if ( argc == 1 ) {
            rep = new CSVReporter( cout );
        }
        else {
            rep = new XMLReporter( cout );
        }

        string word;
        rep->ReportHeader();
        while( ( word = p.NextWord() ) != "" ) {
            if ( ! d.Check( word ) ) {
                rep->ReportError( word, p.Context(), p.LineNo(), subtext );
            }
        }
        rep->ReportFooter();
        delete rep;
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
