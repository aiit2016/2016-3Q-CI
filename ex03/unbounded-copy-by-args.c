#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc, char **argv) /* assume that argc == 3 */
{
  char buf[16];
  strcpy(buf, argv[1]); /* argv[1] + argv[2] */
  strcat(buf, argv[2]);
  printf("%s\n", buf);
  return 0;
}

