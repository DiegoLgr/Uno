/**
 * @file Interpreter.h
 *
 * @brief Interpreter implementation.
 */
#ifndef UNO_H
#define UNO_H

#include <stdio.h>
#include <iostream>
class Interpreter {
    public:
        Interpreter( void);
        void run( std::string program);

    private:
        bool has_error;

        void error( int line, std::string mssg);
};
#endif

