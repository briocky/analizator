a.out: fun_stack.o alex.o store.o keyword.o parser.o
	$(CC) $^ -o analizator
