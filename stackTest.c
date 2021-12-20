#include <stdio.h>
#include <stdlib.h>

#include "fun_stack.h"

int main() {
	stack_t stack = NULL;
	stack = put_on_fun_stack(1, "abc", stack);
	stack = put_on_fun_stack(2, "bcd", stack);
	stack = put_on_fun_stack(3, "cde", stack);
	stack = put_on_fun_stack(4, "def", stack);

	res tmp = get_from_fun_stack(stack);
	stack = tmp.first;

	printf("%s\n", tmp.funame);
	
	tmp = get_from_fun_stack(stack);
	stack = tmp.first;

	printf("%s\n", tmp.funame);

	stack_t first = stack;
	while (first != NULL) {
		printf("%d\t%s\n", first -> par, first -> fname);
		first = first -> next;
	}

	tmp = get_from_fun_stack(stack);
	stack = tmp.first;

	printf("%s\n", tmp.funame);

	tmp = get_from_fun_stack(stack);
	stack = tmp.first;

	printf("%s\n", tmp.funame);
}