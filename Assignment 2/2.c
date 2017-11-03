#include <stdio.h>

int main (void)
{
  int exponent = 0;
  unsigned int tmpsum = 0, sum = 0;
  int r = 0;

  r = scanf ("%d", &exponent);
  if (r != 1) {
    puts ("Illegal input");
    return 1;
  }

  if (exponent < 0) {
    puts ("Meet negative exponent, expect positive one. Exiting.");
    return 1;
  }

  // 2^exp
  tmpsum = 2;
  for (int i = 1; i < exponent; i++) {
    tmpsum *= 2;
  }
  sum += tmpsum;
  // 3^exp
  tmpsum = 3;
  for (int i = 1; i < exponent; i++) {
    tmpsum *= 3;
  }
  sum += tmpsum;

  printf("%d\n", sum);
  return 0;
}
