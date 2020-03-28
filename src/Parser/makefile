all: main.o Scanner.o Parser.o AstNode.o
	clang++ main.o Scanner.o Parser.o AstNode.o

main.o: main.cpp
	clang++ -c -g main.cpp

Scanner.o: Scanner.cpp
	clang++ -c -g Scanner.cpp

Parser.o: Parser.cpp
	clang++ -c -g Parser.cpp

AstNode.o: AstNode.cpp
	clang++ -c -g AstNode.cpp
