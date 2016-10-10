#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc, char **argv)
{
  char *s = "Hello, world!";
  size_t len = strlen(s);
  printf("strlen(%s)=%zd\n", s, len);
  return 0;
}

