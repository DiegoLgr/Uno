/**
 * @file main.cpp
 *
 * @brief Entry point for uno cli.
 */
#include "Uno.h"

#include <iostream>
#include <fstream>
#include <streambuf>


void informError( void);
void runFromFile( std::string file_path);
void runRPL( void);


/*
 * @detail test validity of parameters, gets the source code and hadles it to
 *  the Uno interpreter.
 *  It either takes a file path to the source to be executed or nothing. in the
 *  later case an interactive RPL is launched.
 */
int main( int argc, char *argv[]){
    if (argc > 2){
        informError();
    }else if (argc == 2){
        runFromFile( argv[1]);
    }else{
        runRPL();
    }
}

void informError( void){
    std::cout << "Usage: uno [script]\n";
    std::exit (EXIT_FAILURE);
}

void runFromFile( std::string file_path){
    Uno uno;
    std::ifstream file( file_path);
    std::string source((std::istreambuf_iterator<char>(file)),
                        std::istreambuf_iterator<char>());
    uno.run( source);
}

void runRPL( void){
    Uno uno;
    std::string source;
    while( true){
        std::cout << "Uno ~> ";
        std::getline( std::cin, source);
        uno.run( source);
    }
}
