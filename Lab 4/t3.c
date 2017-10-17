#include <stdio.h>

// #define ABS(a) ((a)>=0?(a):(-a))

int main (void)
{
  int a = 0, b = 0;
  puts ("Please input two integers:");
  scanf ("%d %d", &a, &b);
  printf (
    "Between %d and %d, %d has a greater absolute value.\n",
    a, b,
    // ABS(a) >= ABS(b) ? a : b
    (a >= 0 ? a : -a) >= (b >= 0 ? b : -b) ? a : b
  );
  return 0;
}
