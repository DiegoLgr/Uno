/**
 * @file Interpreter.h
 *
 * @brief Interpreter implementation.
 */
#ifndef UNO_H
#define UNO_H

#include <iostream>
#include <memory>
#include <vector>

#include "../Expr/Expr.h"
#include "../Scanner/Scanner.h"
#include "../Parser/Parser.h"


class Interpreter {
    public:
        Interpreter( void);
        void run( std::string program);

    private:
        bool has_error;
        void error( int line, std::string mssg);
};
#endif

