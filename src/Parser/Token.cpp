#include "Token.h"
#include <string>

Token::Token( int t, std::string lex, int lin){
   type = t;
   lexeme = lex;
   line = lin;
}

int Token::getType( void){
    return type;
}

std::string Token::toString( void) const {
    return lexeme;
}
