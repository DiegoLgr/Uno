#include <iostream>
#include <memory>


typedef struct Token Token;
typedef struct Plus Plus;
typedef struct Minus Minus;
typedef struct Star Star;
typedef struct Slash Slash;
typedef struct Number Number;

struct TokenVisitor {
    virtual void visit( std::unique_ptr<Token> t)=0;
    virtual void visit( Plus p)=0;
    virtual void visit( Minus m)=0;
    virtual void visit( Star s)=0;
    virtual void visit( Slash s)=0;
    virtual void visit( Number n)=0;
};

struct Token {
    virtual void accept( TokenVisitor* v) const =0;
    virtual ~Token(){}
};

struct Plus: public Token {
    void accept( TokenVisitor* v) const { v->visit( *this); }
};

struct Minus: public Token {
    void accept( TokenVisitor* v) const { v->visit( *this); }
};

struct Star: public Token {
    void accept( TokenVisitor* v) const { v->visit( *this); }
};

struct Slash: public Token {
    void accept( TokenVisitor* v) const { v->visit( *this); }
};

struct Number: public Token {
    explicit Number( float val) : value{val}{}
    void accept( TokenVisitor* v) const { v->visit( *this); }
    float value;
};
