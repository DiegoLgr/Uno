uno: Build/main.o Build/Uno.o Build/Scanner.o Build/Token.o
	clang++ Build/main.o Build/Uno.o Build/Scanner.o Build/Token.o -o uno

Build/main.o: src/main.cpp
	clang++ -c src/main.cpp -o Build/main.o

Build/Uno.o: src/Uno.cpp
	clang++ -c src/Uno.cpp -o Build/Uno.o

Build/Scanner.o: src/Scanner.cpp
	clang++ -c src/Scanner.cpp -o Build/Scanner.o

Build/Token.o: src/Token.cpp
	clang++ -c src/Token.cpp -o Build/Token.o

