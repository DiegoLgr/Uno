#ifndef SCANNER_H
#define SCANNER_H

#include "Token.h"

#include <list>
#include <map>
#include <string>

class Scanner{
    /*
     * Te scaner moves along a raw source code making a list of tokens.
     * To scann a source code You must initialize the scanner by caling its
     * constructor with a string containing the raw source and call
     * scanTokens
     */

    public:
        explicit Scanner( std::string src);
        std::list<Token> getTokens( void);
        void scanTokens( void);

    private:
        std::string source;
        std::list<Token> tokens;
        std::map<std::string,int> keywords;
        std::string::iterator current; //The caracter bein scanned.
        std::string::iterator start; //First character in the lexeme being scanned.
        int line; //Line number in the source of the current lexeme.
        bool error;

        Token nextToken( void);
        bool followedBy( char c);
        int scanComment( void);
        int scanNumber( void);
        int scanWord( void);
};
#endif
