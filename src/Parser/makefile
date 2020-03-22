all: main.o Ast.o
	clang++ main.o Ast.o

main.o: main.cpp
	clang++ -c main.cpp

Ast.o: Ast.cpp
	clang++ -c Ast.cpp
