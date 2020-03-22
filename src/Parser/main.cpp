#include <string>
#include <iostream>
#include <vector>

#include "Token.h"
#include "Ast.h"


void cleanStack (void) {
    int vector[200] = {0};
    for (auto i:vector) std::cout << i;
    std::cout << std::endl;
}

std::vector <Token> scan( void){
    std::vector <Token> l;
    l.push_back( Token{ TokenType::NUMBER, "1" });
    l.push_back( Token{ TokenType::PLUS, "+" });
    l.push_back( Token{ TokenType::NUMBER, "2" });
    l.push_back( Token{ TokenType::STAR, "*" });
    l.push_back( Token{ TokenType::NUMBER, "3" });
    return l;
}

class Parser {
    public:
        Parser( const std::vector<Token>& tokens):
            tokens( tokens)
        {}

        Parser* parse(){ parse( 0, tokens.end(), TokenType::EQUALITY)};

        Node* getAst();

    private:
        const std::vector<Token>& tokens;
        Node* ast;

        Node* parse( int start, int end, TokenType operation);
};

Node* Parser::getAst( void){
    return ast;
}

Parser* Parser::parse(){
    TokenType operation = PLUS;
    ast = parse( 0, tokens.end(), operation);
    return this;
};

Node* Parser::parse( int start, int end, ExpressionType expression){
    while (expression != ExpressionType::NONE){
        //i is where the token is.
        if (int i = findToken( start, end, expression) != -1){
            return new Node{ sub_vector, i}; //sub_vector = vector start->end;
        }else{
            expression++;
        }
    }
    return nullptr;
}

Node constructor{
    const auto expression_left = nextExpressionLeft( expression);
    Node* child_left = parse( tokens, start, i, expresion_left);
    const auto expression_right = nextExpressionRight( expression);
    Node* child2_right = parse( tokens, i, end, expression_right);
    return new Node{ tokens[i], child1, child2 };
}

find{
        for (int i = start; i < end; ++i){
    if (match( tokens[i].type, expression)){
    }
}

ExpressionType Parser::nextExpressionLeft( ExpressionType expression){
    if (expression == EQUALITY){
        return EQUALITY;
    }else if (expression == COMPARISON){
        return ADDITION;
    }else if (expression == ADDITION){
        return ADDITION;
    }else if (expression == MULTIPLICATION){
        return MULTYPLICATION;
    }else (expression == UNARY){
        return NONE;
    }
}

ExpressionType Parser::nextExpressionRight( ExpressionType operation){
    if (expression == EQUALITY){
        return COMPARISON;
    }else if (expression == COMPARISON){
        return ADDITION;
    }else if (expression == ADDITION){
        return MULTIPLICATION;
    }else if (expression == MULTIPLICATION){
        return UNARY;
    }else if (expression == UNARY){
        return UNARY;
    }else{
         NONE;
    }
}

int main( void){
    std::vector <Token> tokens = scan();
    Parser parser{ tokens};
    Node* ast = parser.parse().getAst();
    return 0;
}
