lex lexhelper.l
yacc -d parser.y
gcc lex.yy.c  y.tab.c syntax.h -ll -o parseout
./parseout
