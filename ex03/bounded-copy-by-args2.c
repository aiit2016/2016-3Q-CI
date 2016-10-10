#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc, char **argv) /* assume that argc == 3 */
{
  char *buf;
  int len;

  len = strlen(argv[1]) + strlen(argv[2]);
  buf = malloc(len + 1);
  if (buf == NULL) {
    // error
  }

  strcpy(buf, argv[1]); /* argv[1] + argv[2] */
  strcat(buf, argv[2]);
  printf("%s\n", buf);

  free(buf);
  return 0;
}

