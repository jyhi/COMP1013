#include <stdio.h>

/**
 * Calculate n!.
 *
 * @param n [in] Operand.
 * @return n!.
 */
unsigned fac (const unsigned n)
{
  if (!n)
    return 0;

  unsigned ret = 1;
  for (int i = 2; i <= n; i++)
    ret *= i;

  return ret;
}

int main (void)
{
  int a[3] = {0}; // a, b, and c
  int r = 0;

  puts ("Input a, b and c to calculate a! + b! + c!:");
  for (int i = 0; i < 3; i++) {
    r = scanf ("%d", &a[i]);
    if (r != 1) {
      puts ("Illegal input.");
      return 1;
    }
    if (a[i] < 0) {
      puts ("Expect a natural number, meet a negative number.");
      return 1;
    }
  }

  printf("%d! + %d! + %d! = %d\n", a[0], a[1], a[2], fac(a[0]) + fac(a[1]) + fac(a[2]));
  return 0;
}
