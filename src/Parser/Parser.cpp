#include <memory>
#include <algorithm>
#include <vector>
#include <iostream>

#include "../Uno.h"
#include "../Expr/Expr.h"
#include "Parser.h"

std::array<TokenType, 11> operators{
    // Equality.
    TokenType::EQUAL_EQUAL, TokenType::BANG_EQUAL,

    // Comparisson.
    TokenType::GREATER, TokenType::GREATER_EQUAL, TokenType::LESS, TokenType::LESS_EQUAL,

    // Addition.
    TokenType::PLUS, TokenType::MINUS,

    // Multiplication.
    TokenType::STAR, TokenType::SLASH,

    // Unary.
    TokenType::BANG
};

std::array<TokenType, 2> left_associative{
    TokenType::MINUS, TokenType::SLASH
};



Parser::Parser( const std::vector<Token>& tokens): tokens{ tokens }{
    ast = parse( 0, tokens.size());
};

std::unique_ptr<Expr> Parser::getExpr( void){
    return  move( ast);
}

std::unique_ptr<Expr> Parser::parse( int start, int end){
    if (start >= end-1){
        return std::make_unique<Expr>( tokens[start]);
    }
    int i = find_less_priority_token( start, end);
    std::unique_ptr<Expr> left_expr;
    std::unique_ptr<Expr> right_expr;

    if (is_operator( tokens[i].type)){
        left_expr = parse( start, i);
        right_expr = parse( i+1, end);
    }

    return std::make_unique<Expr>( tokens[i], move( left_expr), move( right_expr));
}

int Parser::find_less_priority_token( int i, int end) const{
    int chosen = i++;
    for (; i < end; i++){
        chosen = choose_lest_priority( chosen, i);
    }
    return chosen;
}

/*
 * True if the next one has less priority or if it has the same but the
 * operation is left associative.
 */
int Parser::choose_lest_priority( int current_id, int next_id) const{
    Token current = tokens[current_id];
    Token next = tokens[next_id];

    if (find_priority( current.type) > find_priority( next.type)){
        return next_id;
    }else if (current.type == next.type && is_left_associative( current.type)){
        return next_id;
    }else{
        return current_id;
    }
}

TokenType* Parser::find_priority ( TokenType type) const{
            auto end = operators.end();
            auto begin = operators.begin();
            auto it = std::find( begin, end, type);
            if ( it == end) return end-1;
            return it;
}

bool Parser::is_operator ( TokenType type) const{
            auto end = operators.end();
            auto begin = operators.begin();
            return end != std::find( begin, end, type);
}

bool Parser::is_left_associative( TokenType type) const{
            auto end = left_associative.end();
            auto begin = left_associative.begin();
            return end != std::find( begin, end, type);
}

