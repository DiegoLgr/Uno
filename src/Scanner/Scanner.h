#ifndef SCANNER_H
#define SCANNER_H

#include "Token.h"

#include <memory>
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
        std::vector<std::unique_ptr<Token>> getTokens( void);

    private:
        void scanTokens( void);
        std::string source;
        std::vector<std::unique_ptr<Token>> tokens;
        std::string::iterator current; //The caracter bein scanned.
        std::string::iterator start; //Start of the lexeme being scanned.

        /**
         * Scans characters until has read a full lexeme and turns it into a
         * token.
         *
         * @returns A token corresponding to the next lexeme.
         */
        std::unique_ptr<Token> nextToken( void);

        bool is_white( char c) const;

        std::unique_ptr<Token> match_operator( char op);
        /**
        * Scans a succesion of digits whit at most one '.' among them.
        *
        * @returns The NUMBER token type.
        */
        std::unique_ptr<Token> scanNumber( void);

        bool is_operator( char c) const;
};
#endif
