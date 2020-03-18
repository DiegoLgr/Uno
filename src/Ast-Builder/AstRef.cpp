/*
 * Reference template
 */
#include <iostream>


typedef struct Visitor Visitor;

typedef struct Expr Expr;
typedef struct Add Add;
typedef struct Mult Mult;
typedef struct Number Number;


struct Visitor {
    virtual void visit( const Expr &e) const = 0;
    virtual void visit( const Add &e) const = 0;
    virtual void visit( const Mult &e) const = 0;
    virtual void visit( const Number &e) const = 0;
};

struct Expr {
    virtual void accept( const Visitor &v) const = 0;
};

struct Add: Expr {
    Add( Expr &e1, Expr &e2): e1(e1), e2(e2){}
    void accept( const Visitor &v) const { v.visit( *this); }

    Expr& e1;
    Expr& e2;
};

struct Mult: Expr {
    Mult( Expr &e1, Expr &e2): e1(e1), e2(e2){}
    void accept( const Visitor &v) const { v.visit( *this); }

    Expr& e1;
    Expr& e2;
};

struct Number: Expr {
    Number( float v): v(v){}
    void accept( const Visitor &v) const { v.visit( *this); }

    float v;
};

