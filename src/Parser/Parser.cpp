#include <memory>
#include "Token.h"
#include "AstNode.h"


Parser::Parser( const std::vector<Token>& tokens): tokens{ tokens }{
    unique_ptr<AstNode> ast = parse( 0, tokens.end());
};

std::unique_ptr<AstNode> parse( int start, int end){
    if (start == end){
        return make_unique<AstNode>( tokens[start]);
    }
    int i = find_less_priority_token( start, end);
    std::unique_ptr<AstNode> left_expr = parse( start, i);
    std::unique_ptr<AstNode> right_expr = parse( i, end);

    return make_unique<AstNode>( tokens[i], left_expr, right_expr);
}

int find_less_priority_token( int i, int end) const{
    int chosen = i++;
    for( i; i < end; i++){
        choose_lest_priority( chosen, i)
    }
    return chosen;
}

/*
 * True if the next one has less priority or if it has the same but the
 * operation is left asociative.
 */
bool choose_lest_priority( int cuerrent_id, int next_id) const{
    Token current = tokens[current_id];
    Token next = tokens[next_id];
    if (current.type < next.type){
        return current_id;
    }else{

        bool is_left_associative =
            Token::left_associative.end()
                ==
            std::find(
                     Token::left_asociative.begin(),
                     Token::lect_asociative.end(),
                     current.type
            );

        if (is_left_associative){
            return current_id;
        }else{
            return next_id;
        }
    }
}
