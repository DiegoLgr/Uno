#include <memory>
#include <algorithm>
#include <vector>

#include "Token.h"
#include "AstNode.h"
#include "Parser.h"


Parser::Parser( const std::vector<Token>& tokens): tokens{ tokens }{
    ast = parse( 0, tokens.size());
};

std::unique_ptr<AstNode> Parser::parse( int start, int end){
    if (start == end){
        return std::make_unique<AstNode>( tokens[start]);
    }
    int i = find_less_priority_token( start, end);
    std::unique_ptr<AstNode> left_expr = parse( start, i);
    std::unique_ptr<AstNode> right_expr = parse( i, end);

    return std::make_unique<AstNode>( tokens[i], move( left_expr), move( right_expr));
}

int Parser::find_less_priority_token( int i, int end) const{
    int chosen = i++;
    for (; i < end; i++){
        choose_lest_priority( chosen, i);
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
    if (current.type < next.type){
        return current_id;
    }else{

        bool is_left_associative =
            left_associative.end()
                ==
            std::find(
                     left_associative.begin(),
                     left_associative.end(),
                     current.type
            );

        if (is_left_associative){
            return current_id;
        }else{
            return next_id;
        }
    }
}
