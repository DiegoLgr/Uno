#include <iostream>


typedef struct Visitor Visitor;
typedef struct Expr Expr;
typedef struct Number Number;
typedef struct Add Add;
typedef struct Mult Mult;

// VISITOR

struct Visitor {
    virtual void visit( Expr &e) = 0;
    virtual void visit( Number &n) = 0;
    virtual void visit( Add &a) = 0;
    virtual void visit( Mult &m) = 0;
};

// EXPRESSIONS

struct Expr {
    virtual void accept( Visitor &v) = 0;
};

struct Add: Expr{
    Add( Expr &e1, Expr &e2): e1(e1), e2(e2){}

    void accept( Visitor &v){
        v.visit( *this);
    }

    Expr &e1;
    Expr &e2;
};

struct Mult: Expr{
    Mult( Expr &e1, Expr &e2): e1(e1), e2(e2){}

    void accept( Visitor &v){
        v.visit( *this);
    }

    Expr &e1;
    Expr &e2;
};

struct Number: Expr {
    Number( float v){ this->v = v; }

    void accept( Visitor &v){
        v.visit( *this);
    }

    float v;
};

// PRINTER

struct Printer: Visitor {
    void visit( Expr &e){ e.accept( *this); }

    void visit( Number &n){ std::cout << n.v; }

    void visit( Add &a){
        visit( a.e1);
        std::cout << " + ";
        visit( a.e2);
    }

    void visit( Mult &m){
        visit( m.e1);
        std::cout << " * ";
        visit( m.e2);
    }
};

int main ( void){
    Number &n1 = *new Number{ 1 };
    Number &n2 = *new Number{ 2 };
    Number &n3 = *new Number{ 3 };
    Number &n4 = *new Number{ 4 };

    Add &a1 = *new Add{ n1, n2 };
    Add &a2 = *new Add{ a1, n3 };
    Mult &m = *new Mult{ a2, n4 };

    Printer p;
    p.visit( m);
    std::cout << std::endl;

    return 0;
}
