#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

int read_file(char *filename, char *buf)
{
  FILE *fp;
  size_t size;
  fp = fopen(filename, "rb");
  if (fp == NULL) return -1;
  fseek(fp, 0, SEEK_END);
  size = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  fgets(buf, size, fp);
  fclose(fp);
  return 0;
}

int print_file(char *filename)
{
  char buf[4];
  if (read_file(filename, buf) < 0) return -1;
  puts(buf);
  return 0;
}

int mysystem(char *cmd)
{
  return system(cmd);
}

int main(int argc, char **argv)
{
  if (argc < 2) return -1;
  print_file(argv[1]);
  return 0;
}
