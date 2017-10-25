#include <stdio.h>

int main (void)
{
  int n = 0;
  scanf ("%d", &n);

  if (n < 0) {
    n = -n;
  }

  n = n + n;

  printf ("%d", n); // Not needed per requirement

  return 0;
}
