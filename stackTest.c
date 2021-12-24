#include <stdio.h>
#include <stdlib.h>

#include "fun_stack.h"

int main() {
	stack = NULL;
	put_on_fun_stack(1, "abc");
	put_on_fun_stack(2, "bcd");
	put_on_fun_stack(3, "cde");
	put_on_fun_stack(4, "def");

	printf("%s\n", get_from_fun_stack());
	printf("%d\n", top_of_funstack());
	stack_t first = stack;
	while (first != NULL) {
		printf("%d\t%s\n", first -> par, first -> fname);
		first = first -> next;
	}
	return 0;
}