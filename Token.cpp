#include "Token.h"
#include <string>

Token::Token( int t, std::string lex, int lin){
   type = t;
   lexeme = lex;
   line = lin;
}

std::string Token::toString( void) {
    return std::to_string( type) + " " + lexeme;
}
