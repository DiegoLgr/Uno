#include <list>
#include <string>

class Scanner{
    public:
        Scanner( std::string src);
        std::list<std::string> scanTokens( void);
    private:
        std::string source;
};
