#include <stdio.h>

int main (void)
{
  int a = 0, b = 0;

  puts ("Input 2 integers:");
  scanf ("%d %d", &a, &b);
  printf ("The bigger one is %d\n", a >= b ? a : b);

  return 0;
}
