#include <iostream>


struct Expr {};

template <class E1, class E2>
struct Add: Expr{
    Add( E1 *e1, E2 *e2){
        this->e1 = e1;
        this->e2 = e2;
    }

    E1 *e1;
    E2 *e2;
};

struct Number: Expr {
    Number( float v){ this->v = v; }
    float v;
};


int main ( void){
    Number *n1 = new Number{ 1 };
    Number *n2 = new Number{ 2 };
    Number *n3 = new Number{ 3 };
    Number *n4 = new Number{ 4 };

    Add <Number, Number> *a1 = new Add <Number, Number>{ n1, n2 };
    Add <Add <Add, Number>, Number> *a2 =
            new Add <Add <Add, Number>, Number>{ a1, n3 };
    Add <Number, Add <Add <Add, Number>, Number> *a3 =
            new Add <Add <Add, Number>, Number>{ a2, n4 };

    std::cout << a2->e1->v << " + ";
    std::cout << a2->e2->e1->v << " + ";
    std::cout << a2->e2->e2->e1->v << " + ";
    std::cout << a2->e2->e2->e2->v << std::endl;

    return 0;
}
