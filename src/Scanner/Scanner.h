#ifndef SCANNER_H
#define SCANNER_H

#include "../Uno.h"

#include <vector>
#include <map>
#include <string>

class Scanner{
    /**
     * Turns a string of source code into a list of tokens.
     *
     * To scann a source code You must initialize the scanner by caling its
     * constructor with a string containing the raw source.
     * To get the list of tokens use getTokens.
     * Creates a the complete list of tokens corresponding to the source
     * string.
     */

    public:
        explicit Scanner( std::string src);
        /**
         * @returns The complete list of tokens corresponding to the source
         * string.
         */
        std::vector<Token> getTokens( void);



    private:
        void scanTokens( void);
        std::string source;
        std::vector<Token> tokens;
        std::string::iterator current; //The caracter bein scanned.
        std::string::iterator start; //Start of the lexeme being scanned.
        int line; //Line number in the source of the lexeme being scanned.
        bool error; //Wrong character (or in wrong position) found.

        /**
         * Scans characters until has read a full lexeme and turns it into a
         * token.
         *
         * @returns A token corresponding to the next lexeme.
         */
        Token nextToken( void);

        /**
        * Scans a succesion of digits whit at most one '.' among them.
        *
        * @returns The NUMBER token type.
        */
        TokenType scanNumber( void);
};
#endif
