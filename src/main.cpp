#include <iostream>
#include <string>
#include "dictionary.hpp"
#include "error.hpp"
using namespace std;

int main() {
    cout << "scheck version 0.1" << endl;
    Dictionary d( "data/not-there-mydict.dat" );
    string word;
    string line;
    while( getline( cin, line ) )  {
        //parse( line );
    }
    if ( d.Check( word ) ) {
        cout << word << " is OK\n";
    }
    else {
        cout << word << " is misspelt \n";
    }
}
