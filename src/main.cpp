/**
 * @file main.cpp
 * @brief uno language interpreter.
 * @synopsis uno [path_to_scritp]
 *  if a path is given, it's code is run.
 *  if uno is called without arguments, an interactive RPL is launched.
 */
#include "Uno.h"

#include <iostream>


int main( int argc, char *argv[]){
    Uno uno;
    if (argc > 2){
        std::cout << "Usage: uno [script]\n";
        exit (EXIT_FAILURE);
    }else if (argc == 2){
       uno.runFile( argv[1]);
    }else{
        uno.runPrompt();
    }
}
