#include <stdio.h>

int main (void)
{
  // int value1, value2, sum;
  float value1, value2, sum;
  value1 = 50;
  value2 = 25;
  sum = value1 + value2;
  // printf("The sum of %d and %d is %d\n", value1, value2, sum);
  // printf("The sum of %f and %f is %f\n", value1, value2, sum);
  printf("The sum of %.1f and %f is %f\n", value1, value2, sum);
  return 0;
}
