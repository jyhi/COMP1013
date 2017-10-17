#include <stdio.h>

int main (void)
{
  int a = 0, b = 0;
  puts ("Please input two integers:");
  scanf ("%d %d", &a, &b);
  printf ("Between %d and %d, %d is greater.\n", a, b, (a >= b ? a : b));
  return 0;
}
