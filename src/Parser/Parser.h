#ifndef PARSER_H
#define PARSER_H
class Parser {
    public:
        explicit Parser ( const std::vector<Token>& tokens);
        AstNode getAst() const;

    private:
        std::vector<Token> tokens;
        AstNode ast;

        std::unique_ptr<AstNode> parse( int start, int end);
};
#endif
