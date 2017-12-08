#include <stdio.h>

#define BUFSIZE 4096
#define BUFSIZE_SCANF "4095"

static void inverse (int *nums, const size_t left, const size_t right);

int main (void)
{
  int input[BUFSIZE] = {0};
  int i = 0, r = 0;

  puts ("Please input an array of integers (-1 to end):");
  for (; i < BUFSIZE - 1; i++) {
    r = scanf ("%d", &input[i]);
    if (r != 1) {
      puts ("Invalid input.");
      return 1;
    }
    if (input[i] == -1)
      break;
  }

  // If the input is not ended by -1, force it to mark an end.
  if (i >= BUFSIZE - 2)
    input[BUFSIZE - 1] = -1;

  inverse (input, 0, i);
  for (int j = 0; j < i; j++) {
    printf ("%d ", input[j]);
  }
  putchar ('\n');

  return 0;
}

static void inverse (int *nums, const size_t left, const size_t right)
{
  int tmp = 0;

  for (size_t i = left; i < (right - left) / 2; i++) {
    tmp = nums[right - 1 - i];
    nums[right - 1 - i] = nums[i];
    nums[i] = tmp;
  }
}
