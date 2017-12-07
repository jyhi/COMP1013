#include <stdio.h>

/**
 * Calculate the average number of the given integers.
 *
 * @param nums   [in] A series of integers.
 * @param length [in] Length of nums. If length is larger than the actual size
 *                    of nums, the behavior is undefined.
 * @return The average number of nums.
 */
int average (const int *restrict nums, const size_t length)
{
  if (!nums || length == 0)
    return 0;

  int sum = 0;

  for (size_t i = 0; i < length; i++) {
    sum += nums[i];
  }

  return sum / length;
}

int main (void)
{
  int a[50] = {0};
  int count = 0;
  int r = 0;

  puts ("Input a sequence of integers (-1 to stop):");
  for (; count < 50; count++) {
    r = scanf ("%d", &a[count]);
    if (r != 1) {
      puts ("Read error.");
      return 1;
    }
    if (a[count] == -1)
      break;
  }

  // NOTE: count Starts at 0. Although here a[count] is -1, with length = count
  // this -1 is simply omitted.

  printf("The average is %d.\n", average (a, count));
  return 0;
}
