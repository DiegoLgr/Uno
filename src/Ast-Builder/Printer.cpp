#include <iostream>

#include "Ast.cpp"


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




/*
 * VISITOR PATTERN:

    * Printer want's to be able to print expresions, but he doesn't know how
    * to print a generic expresion and expresions dont even know there is such
    * a thig as 'printing'. So Prety Printer has a problem...

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
    * In this case the problem is we know some expresion have subexpresion, but
    * don't know which kind, specialy, we don't know which members it has or
    * how many. By implementing the visitor why can delay the acces to its
    * members until having visited it and thus knowing its type.
*/
