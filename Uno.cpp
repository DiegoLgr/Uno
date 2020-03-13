#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <streambuf>


using namespace std;

void runFile( string path);
void runPrompt( void);
void run( string program);


int main( int argc, char *argv[]){
    if (argc > 2){
        cout << "Usage: uno [script]\n";
        exit (EXIT_FAILURE);
    }else if (argc == 2){
       runFile( argv[1]);
    }else{
        runPrompt();
    }
}

void runFile( string path){
    ifstream file( path);
    string program((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    run( program);
}

void runPrompt( void){
    string line;
    while( true){
        cout << "Uno ~> ";
        getline( cin, line);
        run( line);
    }
}

void run( string program){
    cout << program <<"\n";
}
