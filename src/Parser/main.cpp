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


class Subchain {
    public:
        const int start, end;

        Subchain( int start, int end);
        Subchain explicit( std::vector<Token>& tokens); //Esto con un move
        get(i) //Este lo vamos a overlodear.


    private:
        const std::vector<Token>& tokens;
};

// --------- PARSER -----------
class Parser {
    public:
        Parser( const Subchain tokens);

        Parser* parse(){ parse( 0, tokens.end(), TokenType::EQUALITY)};
        Ast getAst();//move.

    private:
        const Subchain tokens;
        Ast ast;
};

Parser* Parser::parse(){
    ast = Expression{ tokens};
    return this;
};

class Expression{
    protected:
        equality();
        comparisson();

    private:
        Subexpression subexpression;
}

Expression::Expression( tokens){
   subexpression = equality();
}

Subexpression Expression::equality( void){
    if (tokens.find( equality_set)){ // tokens.find -> {Substring | None}
        return new Equality{ tokens };
    }else{
        return comparisson( tokens);
    }
}

Comparisson Expression::comparisson( void){
    if (tokens.find( comparisson_set)){ // tokens.find -> {Substring | None}
        return new Comparisson{ tokens };
    }else{
        return addition( tokens);
    }
}

// --------- EXPRESSIONS -----------
class Equality: Subexpression{
    public:
        Equality( Subchain tokens;)

    private:
        Set<Token> equality_set{ , };

        Token token;
        Equality* left_expr;
        Comparison* left_expr;
}

Equality::Equality( Subchain tokens ){
    token = tokens.token();
    left_expr = equality( tokens.left_subexpression);
    rigth_expr = comparison{ tokens.right_substring() };
}

class Distinct: Equality{};
class Equals: Equality{};
class Comparison: Equality{};
class Greater: Comparison {};
class Leasser: Comparison {};
class Addition: Comparison {};
class Plus: Addition{};
class Minus: Addition{};
class Multiplication: Addition{};
class Times{}: Multiplication;
class Over{}: Multiplication;
class Unary{}: Multiplication;
class Not{}: Unary;
class Minus{}: Unary;
class Primary{}: Unary;
// And the primary tipes
// .
// .
// .






Node( Subchain tokens){
    token = tokens.current();

    const auto expression_left = nextExpressionLeft( expression);
    Subchain left_chain = tokens.getLeftSubchain();
    Node* child_left = parse( left_chain, expresion_left);

    const auto expression_right = nextExpressionRight( expression);
    Subchain right_chain = tokens.getRightSubchain()
    Node* child_left = parse( right_chain, expresion_right);

    return new Node{ tokens.current(), left_child, right_child }
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
    Subchain tokens = scan();
    Parser parser{ tokens};
    Ast ast = parser.parse().getAst();
    return 0;
}
