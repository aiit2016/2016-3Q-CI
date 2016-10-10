#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc, char **argv)
{
  char buf[16];
  printf("Name>");
  fgets(buf, sizeof(buf), stdin);
  printf("Hello, %s\n", buf);
  return 0;
}

