#ifndef PARSER_H
#define PARSER_H
class Parser {
    public:
        explicit Parser ( const std::vector<Token>& tokens);
        AstNode getAst() const;

    private:
        std::vector<Token> tokens;
        std::unique_ptr<AstNode> ast;

        std::unique_ptr<AstNode> parse( int start, int end);
        int find_less_priority_token( int i, int j) const;
        int choose_lest_priority( int current_id, int next_id) const;
};
#endif
