#include <stdio.h>

static int prime (int n);
static int biggestDivisor(int n);

int main (void)
{
  int n = 0;
  int r = 0;

  puts ("Please input a number to check if it's a prime number:");
  r = scanf ("%d", &n);
  if (r != 1) {
    puts ("Invalid input.");
    return 1;
  }

  if (prime (n)) {
    puts ("The input number is a prime number.");
  } else {
    printf ("The biggest divisor of %d is %d.\n", n, biggestDivisor(n));
  }

  return 0;
}

static int prime (int n)
{
  for (int i = 2; i <= n / 2; i++) {
    if (!(n % i))
      return 0;
  }

  return 1;
}

static int biggestDivisor(int n)
{
  for (int i = n / 2; i > 1; i--) {
    if (!(n % i))
      return i;
  }

  return n;
}
