#include "Token.h"

#include <list>
#include <string>

class Scanner{
    public:
        Scanner( std::string src);
        std::list<Token> scanTokens( void);
    private:
        std::string source;
};
