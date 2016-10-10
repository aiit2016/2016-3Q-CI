#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc, char **argv)
{
  char buf[16];
  if (argc < 2) return -1;
  char *dst = buf;
  char *ptr = argv[1];
  while (*ptr) {
    *dst++ = *ptr++;
  }
  *dst = 0;
  printf("%s\n", buf);
  return 0;
}

