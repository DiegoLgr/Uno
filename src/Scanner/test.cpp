#include "Scanner.h"


class ValueVisitor: public TokenVisitor {
    public:
        explicit ValueVisitor( std::unique_ptr<Token> t){
            visit( move( t));
        };

        virtual void visit( std::unique_ptr<Token> t){ t->accept( this); }
        virtual void visit( Plus p){}
        virtual void visit( Minus m){}
        virtual void visit( Star s){}
        virtual void visit( Slash s){}
        virtual void visit( Number n){ value = n.value; }

        float get_value( void) const { return value; }

    private:
        float value;
};

int main ( void){
    std::cout << "Input str 2+2" << std::endl;
    Scanner s{ "2+2" };
    std::cout << "scanner done" << std::endl;
    ValueVisitor v{ move( s.getTokens()[0]) };
    std::cout << "Visitor created " << std::endl;
    std::cout << "Test: " << v.get_value() << " ~~ Finitoo ~~" << std::endl;
}
