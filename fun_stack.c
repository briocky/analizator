#include "fun_stack.h"

#include <stdlib.h>
#include <string.h>

//stack_t stack = malloc(sizeof stack);
//stack -> next = NULL;

int top_of_funstack(void) {
	return stack -> par;
}

void put_on_fun_stack( int par_level, char *funame ) {
	stac_t new = malloc(sizeof new);
	new -> fname = malloc(strlen(funame) + 1 * sizeof(char));
	new -> next = stack;
	new -> par = par_level;
	new -> fname = funame;
	stack = new;
}

char* get_from_fun_stack( void ) {
	char *name = malloc(strlen(stack -> fname) + 1 * sizeof(char));
	name = stack -> fname;
	stac_t tmp = stack;
	stack = stack -> next;
	free(tmp -> fname);
	free(tmp -> next);
	free(tmp);
	return name;
}