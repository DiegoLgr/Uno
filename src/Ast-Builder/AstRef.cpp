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
    virtual void visit( const Expr &e) = 0;
    virtual void visit( const Add &e) = 0;
    virtual void visit( const Mult &e) = 0;
    virtual void visit( const Number &e) = 0;
};

struct Expr {
    virtual void accept(  Visitor &v) const = 0;
};

struct Add: public Expr {
    Add( const Expr &e1, const Expr &e2): e1(e1), e2(e2){}
    void accept( Visitor &v) const { v.visit( *this); }

    const Expr& e1;
    const Expr& e2;
};

struct Mult: public Expr {
    Mult( const Expr &e1, const Expr &e2): e1(e1), e2(e2){}
    void accept( Visitor &v) const { v.visit( *this); }

    const Expr& e1;
    const Expr& e2;
};

struct Number: public Expr {
    Number( const float v): v(v){}
    void accept( Visitor &v) const { v.visit( *this); }

    const float v;
};

