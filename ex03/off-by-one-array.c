#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc, char **argv)
{
  char buf[4];
  strcpy(buf, "K&RC");
  printf("%s\n", buf);
  return 0;
}

