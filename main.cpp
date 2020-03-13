#include "Uno.h"

#include <iostream>
#include <stdlib.h>
using namespace std;

int main( int argc, char *argv[]){
    Uno uno;
    if (argc > 2){
        cout << "Usage: uno [script]\n";
        exit (EXIT_FAILURE);
    }else if (argc == 2){
       uno.runFile( argv[1]);
    }else{
        uno.runPrompt();
    }
}
