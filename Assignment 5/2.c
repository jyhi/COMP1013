#include <stdio.h>

#define BUFSIZE 512
#define BUFSIZE_SCANF "511"

/**
 * Print integer array a's extreme values, [left, right).
 *
 * @param a [in] The array to search.
 * @param left [in] The left index.
 * @param right [in] The right index.
 */
void print_extreme (const int *a, const int left, const int right)
{
  if (!a)
    return;

  int min = a[0];
  int max = a[0];

  for (int i = left; i < right; i++) {
    if (a[i] < min) {
      min = a[i];
    } else if (a[i] > max) {
      max = a[i];
    }
  }

  printf ("Maximum = %d, minimum = %d\n", max, min);
}

int main (void)
{
  int a[BUFSIZE] = {0}, count = 0;
  int r = 0;

  puts ("Input a sequence of integers (end with -1)...");
  for (count = 0; count < BUFSIZE; count++) {
    r = scanf ("%d", a + count);
    if (r != 1) {
      puts ("Illegal input.");
      return 1;
    }
    if (a[count] == -1)
      break;
  }

  // Since parameter right is exclusive, -1 is not considered by print_extreme.
  print_extreme (a, 0, count);

  return 0;
}
