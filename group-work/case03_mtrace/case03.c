// gcc -g -o case03 case03.c
// export MALLOC_TRACE=./case03.log
// ./case03
// mtrace case03 $MALLOC_TRACE > ./case03_pretty.log
// valgrind --leak-check=yes ./case03 2> case03_valgrind.log
#include <mcheck.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int j;

    /* mtrace start */
    mtrace();

    for (j = 0; j < 2; j++)
        malloc(100);            /* Never freed--a memory leak */

    calloc(16, 16);             /* Never freed--a memory leak */

    /* mtrace end */
    muntrace();

    malloc(100);                /* Never freed--a memory leak */

    exit(EXIT_SUCCESS);
}

