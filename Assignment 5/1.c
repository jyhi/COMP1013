#include <stdio.h>

#define BUFSIZE 21
#define BUFSIZE_SCANF "20"

int main (void)
{
  char a[BUFSIZE] = {0};
  int r = 0;

  puts ("Input a sequence of data...");
  r = scanf ("%" BUFSIZE_SCANF "[^\n]", a);
  if (r != 1) {
    puts ("Read error.");
    return 1;
  }

  char *ptr_to_read = a;
  while (*ptr_to_read) {
    printf ("%p: %c\n", ptr_to_read, *ptr_to_read);
    ++ptr_to_read;
  }

  return 0;
}
