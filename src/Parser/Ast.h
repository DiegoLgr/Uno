typedef struct Node Node;
struct Node {
    const Token token;
    Node* child1;
    Node* child2;

    std::string toString();
};

