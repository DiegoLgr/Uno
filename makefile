uno: Build/main.o Build/Uno.o Build/Scanner.o Build/Token.o
	clang++ Build/main.o Build/Uno.o Build/Scanner.o Build/Token.o -o uno

Build/main.o: main.cpp
	clang++ -c main.cpp -o Build/main.o

Build/Uno.o: Uno.cpp
	clang++ -c Uno.cpp -o Build/Uno.o

Build/Scanner.o: Scanner.cpp
	clang++ -c Scanner.cpp -o Build/Scanner.o

Build/Token.o: Token.cpp
	clang++ -c Token.cpp -o Build/Token.o

