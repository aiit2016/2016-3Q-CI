#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc, char **argv)
{
  char *buf;
  if (argc < 2) return -1;
  buf = malloc(strlen(argv[1]));
  if (NULL == buf) {
    fputs("Not enough memory.", stderr);
    return 1;
  }
  strcpy(buf, argv[1]);
  printf("%s\n", buf);
  free(buf);
  return 0;
}

