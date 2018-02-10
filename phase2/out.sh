lex lexhelper.l
yacc -d parser.y
gcc lex.yy.c  y.tab.c -ll -o parseout
./parseout
