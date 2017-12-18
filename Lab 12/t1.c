/* I did not write this code. */
#include <stdio.h>

// void swap (int x, int y) {
//   int temp;
//   temp = x;
//   x = y;
//   y = temp;
// }
void swap (int *x, int *y) {
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

int main ()
{
  int a = 10, b = 20;
  printf("before exchange: a = %d\n, b = %d\n", a, b);
  // swap (a, b);
  swap (&a, &b);
  printf("after exchange: a = %d, b = %d \n", a, b);
  return 0;
}
