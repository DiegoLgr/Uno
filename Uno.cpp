#include "Uno.h"

#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <streambuf>
using namespace std;

Uno::Uno ( void){
    has_error = false;
};

void Uno::runFile( string path){
    ifstream file( path);
    string program((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    run( program);
}

void Uno::runPrompt( void){
    string line;
    while( true){
        cout << "Uno ~> ";
        getline( cin, line);
        run( line);
    }
}


void Uno::run( string program){
    cout << program << "\n";
}
/*
Uno::void run( string program){
    Scanner scanner = new Scanner(program);
    List<Token> tokens = scanner.scanTokens();

    for (Token token : tokens){
        cout << token;
    }
    if (has_error){
        exit(65);
    }
}
*/

void Uno::error( int line, string mssg){
    cout << "[line " << line << " ] Error : " << mssg;
    has_error = true;
}
