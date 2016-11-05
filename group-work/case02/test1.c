#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(void)
{
int *p = (int *)malloc( sizeof(int) * 10 );
printf( "%d\n", p[11] );
;}


