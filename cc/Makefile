all:
	bison -v -d --file-prefix=y compiler.y
	flex compiler.lex
	g++ -std=c++11 -g -o compiler y.tab.c lex.yy.c -lfl -Wno-write-strings
clean:
	rm compiler lex.yy.c y.output y.tab.*

# had to add the -Wno-write-strings to get rid of error
# warning: ISO C++ forbids converting a string constant to ‘char*’ [-Wwrite-strings]