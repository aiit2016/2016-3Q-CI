#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  int status;
  puts("Password>");
  status = authenticate();
  if (!status) { puts("Access denied"); return -10; }
  else puts("Access granted");
  return 0;
}

int authenticate(void) {
  char password[12];
//  printf("%04x\n", password);
  gets(password);
  if (!strcmp(password, "password")) return 1;
  return 0;
}
