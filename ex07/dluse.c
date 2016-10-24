// gcc -O0 -c dluse.c -o dluse.o
// gcc -o dluse dluse.o -ldlsample -L `pwd`
// export LD_LIBRARY_PATH=`pwd`
// ldd ./dluse
// objdump -D dluse
#include <stdio.h>

int add_orig(int x, int y);
int adds_orig(int x, int y);

int main(void)
{
  printf("%d+%d=%d", 3, 4, add_orig(3 ,4));
  return 0;
}

