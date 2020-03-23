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

find{
        for (int i = start; i < end; ++i){
    if (match( tokens[i].type, expression)){
    }
}


// --------- PARSER -----------

class Parser {
    public:
        Parser( const std::vector<Token> tokens);

        Parser* parse();
        ExprNode getAst();//move.

    private:
        const std::vector<Token> tokens;
        ExprNode ast;
};

Parser* Parser::parse(){
    ast = ExprNode{ tokens};
    return this;
};


// ---------- EXPRESSION ----------

class Expr{
    protected:
        equality();
        comparisson();
        adddition();
        multiplication();
        unary();

        //This should be preset, but im tired now.
        equality_set{};
        comparison_set{};
        addition_set{};
        multiplication_set{};
        unary_set{};
        primary_set{};

        Tokens tokens;
};

class Equality: Expr{};
class Comparison: Equality{};
class Addition: Comparison{};
class Multiplication: Addition{};
class Unary: Multiplication{};
class Primary: Unary{};

Equality Expr::equality( tokens){
    if (tokens.find( equality_set)){ // tokens.find -> {Substring | None}
        return new Equality{ tokens };
    }else{
        return comparisson( tokens);
    }
}

Comparison Expr::comparisson( void){
    if (tokens.find( comparisson_set)){ // tokens.find -> {Substring | None}
        return new Comparisson{ tokens };
    }else{
        return addition( tokens);
    }
}

Addition Expr::addition( void){
    if (tokens.find( addition_set)){ // tokens.find -> {Substring | None}
        return new Addition{ tokens };
    }else{
        return multiplication( tokens);
    }
}

Multiplication Expr::multiplication( void){
    if (tokens.find( Multiplication)){ // tokens.find -> {Substring | None}
        return new Multiplication{ tokens };
    }else{
        return unary( tokens);
    }
}

Unary Expr::unary( void){
    if (tokens.find( unary)){ // tokens.find -> {Substring | None}
        return new Unary{ tokens };
    }else{
        return primary( tokens);
    }
}


// ########## NODES ##########

class ExprNode: Expr {
    public:
        ExprNode( tokens);

    private:
        Equality* child;
};

ExprNode::ExprNode( tokens){
    tokens = Subchain{ tokens };
    child = equality( tokens);
}

class EqualityNode: Equality{
    public:
        EqualityNode( Subchain tokens;)

    private:
        Token token;
        Equality* left_expr;
        Comparison* left_expr;
}

EqualityNode::EqualityNode {
    tokens = Subchain{ tokens };
    token = tokens.current();
    right_expr = equality( tokens.left());
    right_expr = comparison( tokens.right());
}

class ComparisonNode: Comparison {
    public:
        ComparisonNode( Subchain tokens)

    private:
        Token token;
        Addition* left_expr;
        Addition* right_expr;
};

ComparisonNode::ComparisonNode( Subchain tokens){
    token = tokens.current();
    right_expr = addition();
    right_expr = addition();
}

class AdditionNode: Addition {
    public:
        AdditionNode( Subchain tokens)

    private:
        Token token;
        Addition* left_expr;
        Multiplication* right_expr;
};

AdditionNode::AdditionNode( Subchain tokens){
    token = tokens.current();
    right_expr = addition();
    right_expr = multiplication();
}

class MultiplicationNode: Multiplication {
    public:
        MultiplicationNode( Subchain tokens)

    private:
        Token token;
        Multiplication* left_expr;
        Unary* left_expr;
};

MultiplicationNode::MultiplicationNode( Subchain tokens){
    token = tokens.current();
    right_expr = multiplication();
    right_expr = unary();
}

class UnaryNode: Unary {
    public:
        UnaryNode( Subchain tokens)

    private:
        Token token;
        Primary* expr;
};

UnaryNode::UnaryNode( Subchain tokens){
    token = tokens.current();
    expr = primary();
}

class Literal: Primary {
    public:
        Literal( Subchain tokens)

    private:
        Token token;
};

Literal::Literal( Subchain tokens){
    token = tokens.current();
}

class Group: Primary {
    public:
        Group( Subchain tokens)

    private:
        Expr expr;
};

Group::Group( Subchain tokens){
    Expr = equality();
}



int main( void){
    Subchain tokens = scan();
    Parser parser{ tokens};
    Ast ast = parser.parse().getAst();
    return 0;
}
