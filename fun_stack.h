#ifndef _FUN_STACK_H_IS_INCLUDED_
#define _FUN_STACK_H_IS_INCLUDED_

typedef struct stack {
	int par;
	char *fname;
	struct stack *next;
} *stack_t;

typedef struct {
	char *funame;
	struct stack *first;
} res;

int top_of_funstack( stack_t stack );  // zwraca par_level - "zagłębienie nawiasowe" przechowywane na szczycie
stack_t put_on_fun_stack( int par_level, char *funame, stack_t stack ); // odkłada na stos parę (funame,par_level)
res get_from_fun_stack( stack_t stack ); // usuwa z wierzchołka parę (funame,par_level), zwraca zdjętą funame

#endif

