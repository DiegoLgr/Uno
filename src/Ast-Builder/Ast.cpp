#include <iostream>


typedef struct Visitor Visitor;

struct Expr { virtual void accept( Visitor &v) = 0; };

typedef struct Add Add;
typedef struct Mult Mult;
typedef struct Number Number;

struct Visitor {
    virtual void visit( Expr &e) = 0;
    virtual void visit( Add &e) = 0;
    virtual void visit( Mult &e) = 0;
    virtual void visit( Number &e) = 0;
};

struct Add: Expr {
    Add( Expr &e1, Expr &e2): e1(e1), e2(e2){}

    void accept( Visitor &v){ v.visit( *this); }

    Expr& e1;
    Expr& e2;
};

struct Mult: Expr {
    Mult( Expr &e1, Expr &e2): e1(e1), e2(e2){}

    void accept( Visitor &v){ v.visit( *this); }

    Expr& e1;
    Expr& e2;
};

struct Number: Expr {
    Number( float v): v(v){}

    void accept( Visitor &v){ v.visit( *this); }

    float v;
};

