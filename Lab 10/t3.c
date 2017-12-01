#include <stdio.h>

int t (const int n)
{
  if (n == 1)
    return 1;
  return t (n / 2) + n;
}

int main (void)
{
  int input = 0;
  int r = 0;

  puts ("Please input a positive integer:");
  r = scanf ("%d", &input);
  if (r != 1) {
    puts ("Illegal input.");
    return 1;
  }

  printf ("T(%d)=%d\n", input, t (input));

  return 0;
}
