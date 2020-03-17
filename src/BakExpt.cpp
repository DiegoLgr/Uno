
/*
 * VISITOR PATTERN:

    * PretyPrinter want's to be able to print expresions, but he doesn't know how
    * to print a generic expresion and expresions dont even know there is such
    * a thig as 'printing'. So Prety Printer has a problem...
    * In particular: (clang error mssg) candidate function not viable: no known
    * conversion from 'Expr' to 'Number' for 1st argument

    * So he decides to ask gently to the expresionto accept to be visited.
    void Visitor::visit( Expr e){
        e.accept( this);
    }

    * The expresion, who is already expecting visitors sends a mssg to
    * PretyPrinter saying: sure, visit me so you can see how I am.
    void Expr::accept( Visitor v){
        v.visit( this); //Now visit is called with the actual type of the expresion
    }

    * So Prety Printer visites the expresion and realizes it is a number, so he
    * prints it haply, beacause he know hot to print numbers. :)
    void Visitor visit( Number n){
        std::cout << n.value << " ";
    }

    * This pattern help us to implement any functionality for a hierarchy of
    * classes by inheriting from an acceptor base class. Note that it is only usefull
    * if we spect the function to be called with a base class as a parametter,
    * if this is not the case, the problem is solved using simple overload.
*/

#include <iostream>

typedef struct Visitor Visitor;
struct Expr {
    void virtual accept( const Visitor *v) const = 0;
};

struct Visitor {
    void visit( const Expr *e) const;
    template <class A>
    void visitAdd( const A) const;

    template <class M>
    void visitMultiply( const M) const;

    void visitNumber( const Number*) const;
};

// Expresions


struct Number final: public Expr {
        Number( float val){ value = val; };

        void accept( const Visitor *v) const { v->visitNumber( this); }

        float value;
};

template <class E1, class E2>
struct Add final: public Expr {
        Add( E1 *e1, E2 *e2){ expr1 = e1; expr2 = e2;};

        void accept( const Visitor *v) const {
            v->visitAdd( this);
        };

        E1 *expr1;
        E2 *expr2;
};

template <class E1, class E2>
struct Multiply final: public Expr {
        Multiply( E1 *e1, E2 *e2){ expr1 = e1; expr2 = e2;};

        void accept( Visitor *v) const {
            v->visitMultiply( this);
        }

        E1 *expr1;
        E2 *expr2;
};


// Visitor
void Visitor::visit( const Expr *e) const {
        e->accept( this);
}

struct PretyPrinter final: public Visitor{
    void visitNumber( Number *n){
        std::cout << n->value << " ";
    }

    template <class A>
    void visitAdd( A *a){
        PretyPrinter pp;
        std::cout << "(+ ";
        pp.visit( a->expr1);
        pp.visit( a->expr2);
    }
    template <class M>
    void visitMultiply( M *m){
        PretyPrinter pp;
        std::cout << "(* ";
        pp.visit( m->expr1);
        pp.visit( m->expr2);
    }
};


Add <Number, Multiply <Number, Number>> *parser( void){
    Number *n1 = new Number{ 1 };
    Number *n2 = new Number{ 0 };
    Number *n3 = new Number{ 8 };
    Multiply<Number, Number> *m = new Multiply<Number, Number>{ n2, n3 };
    Add<Number, Multiply<Number, Number>> *a = new Add<Number, Multiply<Number, Number>>{ n1, m };
    return a;
}

int main( void){
    Add <Number, Multiply <Number, Number>> *root;
    root = parser();
    PretyPrinter prety_printer;
    prety_printer.visit( root);
    std::cout << "\n";
    return 0;
}
