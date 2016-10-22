// gcc -g -o case01 case01.c
// valgrind --leak-check=full --track-origins=yes -v ./case01 2> case01.log
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int foo;
	int *ptr1 = &foo;
	int *ptr2 = malloc(sizeof(int));	// leak
	int *ptr3 = malloc(2 * sizeof(int)); free(ptr3);
	
	if (*ptr1)	// jump depends on uninitialized value
		ptr2[1] = 0xabad1dea;	// invalid write
	else
		ptr2[1] = 0x15bad700;	// invalid write
	ptr2[0] = ptr2[2];	// invalid read
	ptr2[0] = ptr3[1];	// read after free
	ptr3[0] = ptr2[0];	// write after free
	return *ptr1;	// invalid syscall param
}

