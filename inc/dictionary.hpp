#ifndef INC_DICTIONARY_H
#define INC_DICTIONARY_H

#include <string>
#include <set>
#include <fstream>

class Dictionary {
    private:
        std::set <std::string> Words;
    public:
        Dictionary( const std::string & fname ) {
            std::ifstream wlist( fname.c_str() );
            std::string word;
            while( std::getline( wlist, word ) ) {
                Words.insert( word );
            }
        }
        bool Check( const std::string & word ) const {
            return Words.find( word ) != Words.end();;
        }
};

#endif
