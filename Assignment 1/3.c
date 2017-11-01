#include <stdio.h>

#define ABS(a) (((a) >= 0) ? (a) : -(a))

int main (void)
{
  int i = 0, count = 0;
  int ret = 0;

  ret = scanf ("%d", &i);
  if (ret != 1) {
    return 255;
  }

  // Use absolute value (handling negative number)
  i = ABS(i);

  for (; i > 0; count++) {
    i /= 10;
  }

  printf ("%d\n", count);

  return 0;
}
