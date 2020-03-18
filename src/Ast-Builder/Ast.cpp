#include <string>

typedef struct Expr Expr;
typedef struct Equ Equ;
typedef struct Comp Comp;
typedef struct Add Add;
typedef struct Mult Mult;
typedef struct Unary Unary;
typedef struct Group Group;
typedef struct Number Number;
typedef struct String String;
typedef struct Bool Bool;
typedef struct Nil Nil;

struct Visitor {
    virtual void visit( const Equ &e) = 0;
    virtual void visit( const Comp &e) = 0;
    virtual void visit( const Add &e) = 0;
    virtual void visit( const Mult &e) = 0;
    virtual void visit( const Unary &e) = 0;
    virtual void visit( const Group &e) = 0;
    virtual void visit( const Number &e) = 0;
    virtual void visit( const String &e) = 0;
    virtual void visit( const Bool &e) = 0;
    virtual void visit( const Nil &e) = 0;
};

struct Expr {
 virtual void accept( Visitor &v) const = 0;
 };

struct Equ: public Expr {
    Equ( const Expr &e1, const Expr &e2):
        e1(e1),
        e2(e2)
    {}

    void accept( Visitor &v) const { v.visit( *this); }

    const Expr& e1;
    const Expr& e2;
};

struct Comp: public Expr {
    Comp( const Expr &e1, const Expr &e2):
        e1(e1),
        e2(e2)
    {}

    void accept( Visitor &v) const { v.visit( *this); }

    const Expr& e1;
    const Expr& e2;
};

struct Add: public Expr {
    Add( const Expr &e1, const Expr &e2):
        e1(e1),
        e2(e2)
    {}

    void accept( Visitor &v) const { v.visit( *this); }

    const Expr& e1;
    const Expr& e2;
};

struct Mult: public Expr {
    Mult( const Expr &e1, const Expr &e2):
        e1(e1),
        e2(e2)
    {}

    void accept( Visitor &v) const { v.visit( *this); }

    const Expr& e1;
    const Expr& e2;
};

struct Unary: public Expr {
    Unary( const Expr &e1):
        e1(e1)
    {}

    void accept( Visitor &v) const { v.visit( *this); }

    const Expr& e1;
};

struct Group: public Expr {
    Group( const Expr &e1):
        e1(e1)
    {}

    void accept( Visitor &v) const { v.visit( *this); }

    const Expr& e1;
};

struct Number: public Expr {
    Number( const float v):
        v(v)
    {}

    void accept( Visitor &v) const { v.visit( *this); }

    const float v;
};

struct String: public Expr {
    String( const std::string v):
        v(v)
    {}

    void accept( Visitor &v) const { v.visit( *this); }

    const std::string v;
};

struct Bool: public Expr {
    Bool( const bool v):
        v(v)
    {}

    void accept( Visitor &v) const { v.visit( *this); }

    const bool v;
};

struct Nil: public Expr {
    Nil( )
    {}

    void accept( Visitor &v) const { v.visit( *this); }

};

