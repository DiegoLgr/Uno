#ifndef UNO_H
#define UNO_H

#include <stdio.h>
#include <iostream>
class Uno {
    public:
        Uno( void);
        void runFile( std::string path);
        void runPrompt( void);

    private:
        void run( std::string program);
        void error( int line, std::string mssg);
        bool has_error;
};
#endif

