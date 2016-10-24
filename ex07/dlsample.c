// gcc -O0 -fPIC -c dlsample.c
// gcc -shared -o libdlsample.so dlsample.o

int add_orig(int x, int y)
{
  return x + y;
}

int adds_orig(int x, int y)
{
  return add_orig(x * x, y * y);
}

