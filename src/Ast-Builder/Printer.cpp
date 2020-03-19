#include <iostream>
#include <string>

#include "Ast.cpp"


struct Printer: Visitor {
    std::string s {};

    void visit( const Expr &e) { e.accept( *this); }

    void visit( const Number &n) {
        s.append( std::to_string( n.v));
    }

    void visit( const  &e) {
        s.append(" (");
        visit( e.e1);
        s.append(" + ");
        visit( e.e2);
        s.append(" )");
    }

    void visit( const Add &e) {
        s.append(" (");
        visit( e.e1);
        s.append(" + ");
        visit( e.e2);
        s.append(" )");
    }

    void visit( const Mult &m) {
        s.append(" (");
        visit( m.e1);
        s.append(" * ");
        visit( m.e2);
        s.append(" )");
    }

    void print( void) const {
        std::cout << s << std::endl;
    }
};

int main ( void){
/*
    const Number n1 { 1 };
    const Number n2 { 7 };
    const Number n3 { 3 };
    const Number n4 { 4 };

    const Add a1 { Number{ 5 }, n2 };
    const Add a2 { a1, n3 };
    const Mult m { a2, n4 };
*/

    const Add a {
        Mult {
            Add { Number {3}, Number {8} },
            Number {5}
        },
        Add { Number {23}, Number {0} }
    };

    Printer p;
    p.visit( a);
    p.print();
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
