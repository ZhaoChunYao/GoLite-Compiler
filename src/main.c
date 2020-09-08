#include "stdio.h"
#include <string.h>
#include "main.h"
#include "tree.h"
#include "symbol.h"
#include "pretty.h"
#include "codegen.h"

void yyparse();
int yylex();
Prog* root;

int main(int argc, char **argv) {
	if (strcmp(argv[1], "scan") == 0) {
		mode = scan;
		while (yylex()) {
		}
		printf("OK\n");
	} else if (strcmp(argv[1], "tokens") == 0) {
		mode = tokens;
		while (yylex()) {
		}
	} else if (strcmp(argv[1], "parse") == 0) {
		mode = parse;
		yyparse();
		printf("OK\n");
	} else if (strcmp(argv[1], "pretty") == 0) {
		mode = pretty;
		yyparse();
		prettyProg(root);
	}
	else if (strcmp(argv[1], "symbol") == 0) {
		mode = symbol;
		yyparse();
		symProg(root, true);
	} else if (strcmp(argv[1], "typecheck") == 0) {
		mode = typecheck;
		yyparse();
		symProg(root, false);
		printf("OK\n");
	} else if (strcmp(argv[1], "codegen") == 0) {
        	mode = codegen;
        	yyparse();
		    symProg(root, false);
        	codegenProg(root, argv[2]);
        	//printf(argv[2]);
        	printf("OK\n");
    }
	return 0;
}




