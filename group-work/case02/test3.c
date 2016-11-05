#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc, char **argv)
{
int *p = (int *)malloc( sizeof(int) * 10 );
free( p );
free( p );
}

