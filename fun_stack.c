#include "fun_stack.h"

#include <stdlib.h>

//stack_t stack = malloc(sizeof stack);
//stack -> next = NULL;

int top_of_funstack( stack_t stack ) {
	return stack -> par;
}

stack_t put_on_fun_stack( int par_level, char *funame, stack_t stack ) {
	stack_t new = malloc(sizeof new);
	new -> next = stack;
	new -> par = par_level;
	new -> fname = funame;
	return new;
}

res get_from_fun_stack( stack_t stack ) {
	res results;
	results.funame = stack -> fname;
	results.first = stack -> next;
	//free (stack -> fname);
	//free (stack -> next);
	//free (stack);
	return results;
}