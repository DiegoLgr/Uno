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
    Add( const Expr &e1, const Expr &e2): e1(e1), e2(e2){}
    void accept( const Visitor &v) const { v.visit( *this); }

    const Expr& e1;
    const Expr& e2;
};

struct Mult: Expr {
    Mult( const Expr &e1, const Expr &e2): e1(e1), e2(e2){}
    void accept( const Visitor &v) const { v.visit( *this); }

    const Expr& e1;
    const Expr& e2;
};

struct Number: Expr {
    Number( const float v): v(v){}
    void accept( const Visitor &v) const { v.visit( *this); }

    const float v;
};

