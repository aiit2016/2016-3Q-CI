#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(int argc, char **argv) /* assume that argc == 3 */
{
  char buf[16];
  int len;

  len = strlen(argv[1]) + strlen(argv[2]);

  if (len + 1 > sizeof(buf)) {
    puts("error: input too long");
    return -2;
  }

  strcpy(buf, argv[1]); /* argv[1] + argv[2] */
  strcat(buf, argv[2]);
  printf("%s\n", buf);
  return 0;
}

