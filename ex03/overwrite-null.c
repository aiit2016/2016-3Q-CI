#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc, char **argv)
{
  char buf[4][8];
  strcpy(buf[0], "********");
  strcpy(buf[1], buf[0]);
  strcpy(buf[2], buf[1]);
  strcpy(buf[3], buf[2]);
  printf("%s\n", buf[0]);
  return 0;
}

