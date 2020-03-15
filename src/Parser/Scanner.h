#ifndef SCANNER_H
#define SCANNER_H

#include "Token.h"

#include <list>
#include <map>
#include <string>

class Scanner{
    /**
     * Turns a string of source code into a list of tokens.
     *
     * To scann a source code You must initialize the scanner by caling its
     * constructor with a string containing the raw source and call scanTokens
     * To get the list of tokens use getTokens.
     */

    public:
        explicit Scanner( std::string src);

        /**
         * @returns The complete list of tokens corresponding to the source
         * string.
         */
        std::list<Token> getTokens( void);

        /**
         * Creates a the complete list of tokens corresponding to the source
         * string.
         */
        void scanTokens( void);


    private:
        std::string source;
        std::list<Token> tokens;
        std::map<std::string,int> keywords; //Uno's reserved words.
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

        bool followedBy( char c);

        /**
         * Scans until the end of the line.
         *
         * @returns The COMMENT token type.
         */
        int scanComment( void);

        /**
        * Scans a succesion of digits whit at most one '.' among them.
        *
        * @returns The NUMBER token type.
        */
        int scanNumber( void);

        /**
         * Scans throught an uninterrupted succesion of letters and finds it
         * token type.
         *
         * @returns The token Type of the scanned lexeme.
         */
        int scanWord( void);
};
#endif
