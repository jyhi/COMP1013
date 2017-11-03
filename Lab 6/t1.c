#include <stdio.h>

int main (void)
{
  int input = 0;
  int r = 0;

  printf ("Please input a positive integer: ");
  r = scanf ("%d", &input);
  if (r != 1) {
    puts ("Illegal input.");
    return 1;
  }

  // 0 is not considered as a prime
  // https://math.stackexchange.com/questions/539174/is-zero-a-prime-number
  if (input <= 0) {
    puts ("Meet negative number or 0, expect positive one. Exiting.");
    return 1;
  }

  for (int i = 2; i < input; ++i) {
    if (input % i == 0) {
      printf("%d is not a prime.\n", input);
      return 0;
    }
  }

  printf("%d is a prime.\n", input);
  return 0;
}
