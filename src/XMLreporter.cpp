#include "XMLreporter.h"

using std::string;

XMLReporter :: XMLReporter( std::ostream & os )
      : Reporter( os ) {
}

void XMLReporter :: ReportHeader() {
     Out() << "<table>\n";
}

void XMLReporter :: ReportError( const string & word,
                                 const string & context,
                                 unsigned int line,
                                 const string & filename ) {
    Out()   << "  <tr>\n" << "    <td>" << word << "</td>\n"
            << "    <td>" << context << "</td>\n"
            << "    <td>" << line << "</td>\n"
            << "    <td>" << filename << "</td>\n"
            << "  </tr>\n";
}

void XMLReporter :: ReportFooter() {
   Out() << "</table>\n";
}
