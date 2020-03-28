#ifndef PARSER_H
#define PARSER_H
class Parser {
    public:
        explicit Parser ( const std::vector<Token>& tokens);
        std::unique_ptr<AstNode> getAst( void);

    private:
        std::vector<Token> tokens;
        std::unique_ptr<AstNode> ast;

        std::unique_ptr<AstNode> parse( int start, int end);
        int find_less_priority_token( int i, int j) const;
        int choose_lest_priority( int current_id, int next_id) const;
        TokenType* find_priority (TokenType type) const;
        bool is_operator( TokenType type) const;
        bool is_left_associative (TokenType type) const;
};
#endif
