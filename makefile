CC=g++ -std=c++11
CCFLAGS=-Wall
OBJECTS=parser.o lexer.o main.o symboltable.o codegenerator.o symbol.o

compiler: $(OBJECTS)
	$(CC) $(OBJECTS) -ll -o compiler

lexer.cpp lexer.hpp: lexer.l
	flex --header-file=lexer.hpp -o lexer.cpp lexer.l

parser.cpp parser.hpp: parser.ypp lexer.hpp
	bison -d -o parser.cpp parser.ypp

%.o: %.cpp parser.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm -f *.o lexer.cpp lexer.hpp parser.cpp parser.hpp tests/*.asm main
 
.PHONY:
	clean
