#include <stdio.h>

int main (void)
{
  int n = 0;
  int r = 0;

  r = scanf ("%d", &n);
  if (r != 1) {
    puts ("Illegal input");
    return 1;
  }

  for (int i = 0; i <= n / 2 + 1; i++) {
    if (i * i == n) {
      printf ("%d is a perfect square (%d x %d)\n", n, i, i);
      return 0;
    }
  }

  printf ("%d is not a perfect square.\n", n);
  return 0;
}
