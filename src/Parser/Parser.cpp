class Parser {
    public:
        Parser explicit( const std::vector<Token>& tokens);
        getAst() const;

    private:
        std::vector<Token> tokens;
        Ast ast;
        parse( int start, int end);
};

Parser::Parser( const std::vector<Token>& tokens){
    if (!tokens) throw EmptyTokensVector;
    this->tokens = tokens;
    unique_ptr<AstNode> root = parse( 0, tokens.end());
};

std::unique_ptr<AstNode> parse( int start, int end){
    int i = find_next_token( start, end);
    std::unique_ptr<AstNode> left_expr = parse( start, i);
    std::unique_ptr<AstNode> right_expr = parse( i, end);
    return make_unique<AstNode>( tokens[i], left_expr, right_expr);
}

// looks for the less priority token in tokens between i and end.
int find_next_token( int i, int end) const{
    int chosen = i++;
    for( i; i < end; i++){
        if (have_to_change( tokens[chosen], tokens[i])){
            chosen = i;
        }
    }
    return i
}

/*
 * True if the next one has less priority or if it has the same but the
 * operation is left asociative.
 */
bool have_have_to_change( const Token current, const Token next) const{
    if (current.type < next.type){
        return true;
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
            return true;
        }else{
            return false;
        }
    }
}
