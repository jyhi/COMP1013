#include <stdio.h>

int main (void)
{
  int n = 0;
  unsigned int result = 1;
  int i = 0; // Tmp Counter
  int r = 0; // Ret Value

  r = scanf ("%d", &n);
  if (r != 1) {
    puts ("Illegal input.");
    return 1;
  }
  if (n < 0) {
    puts ("Meet negative number, expect positive one. Exiting.");
    return 1;
  }
  if (n >= sizeof (unsigned) * 8) {
    printf ("Warning: N larger than or equal to %d may cause unpredictable output.\n", sizeof (unsigned) * 8);
  }

  // Using while per requirement.
  // i = n;
  // while (i) {
  //   result *= 2;
  //   --i;
  // }

  // Using do-while per requirement.
  // i = n;
  // if (i == 0) goto output;
  //
  // do {
  //   result *= 2;
  //   --i;
  // } while (i);

  // Using for per requirement.
  for (i = n; i; --i) {
    result *= 2;
  }

// output: // For do-while's 0 condition jump
  printf ("2^%d is %u\n", n, result);

  return 0;
}
