#ifndef INC_DICTIONARY_H
#define INC_DICTIONARY_H

#include <string>
#include <set>

class Dictionary {
    private:
        std::set <std::string> Words;
    public:
        Dictionary( const std::string & fname ) {
            Words.insert("dog");
        }
        bool Check( const std::string & word ) const {
            return Words.find( word ) != Words.end();;
        }
};

#endif
