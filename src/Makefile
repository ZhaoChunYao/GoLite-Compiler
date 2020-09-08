all: tiny

y.tab.c y.tab.h: parser.y
	bison -d --yacc parser.y
lex.yy.c: scanner.l y.tab.h
	flex scanner.l
tiny: lex.yy.c y.tab.c y.tab.h tree.c symbol.c type.c codegen.c weeder.c
	gcc main.c main.h tree.c tree.h pretty.c pretty.h symbol.c symbol.h type.c type.h codegen.h codegen.c y.tab.c lex.yy.c y.tab.h weeder.h weeder.c -o tiny -lfl

clean: 
	rm lex.yy.c y.tab.c y.tab.h; rm tiny
