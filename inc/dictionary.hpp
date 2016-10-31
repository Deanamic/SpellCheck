#ifndef INC_DICTIONARY_H
#define INC_DICTIONARY_H

#include <string>
#include <set>
#include <fstream>
#include "error.hpp"

class Dictionary {
    private:
        std::set <std::string> mWords;
    public:
        Dictionary(const std::string & fname) {
            std::ifstream wlist(fname.c_str() );
            if ( !wlist.is_open() ) {
                throw ScheckError("Could not open dictionary file " + fname);
            }
            std::string word;
            while ( std::getline(wlist, word) )
                mWords.insert(word);
            if ( !wlist.eof() ) {
                throw ScheckError("Error reading dictionary file " + fname);
            }
        }
        bool Check(const std::string & word) const {
            return mWords.find(word) != mWords.end();;
        }
};

#endif // ifndef INC_DICTIONARY_H
