#include <stdio.h>

int array[] = {3, 10, 15, 30, 55, 77};

int main (void)
{
  int ins_array[8] = {0};
  int input = 0;
  int r = 0;

  r = scanf ("%d", &input);
  if (r != 1) {
    puts ("Illegal input.");
    return 0;
  }

  // Per requirement, here we do insertion first.

  // Go to the position to insert
  int pos = 0;
  for (; pos < 6; pos++) {
    if (array[pos] >= input)
      break;
  }

  // Insert
  ins_array[pos] = input;

  // Fill the left part
  for (int i = 0; i < pos; i++) {
    ins_array[i] = array[i];
  }
  // Fill the right part
  for (int i = pos; i < 7; i++) {
    ins_array[i + 1] = array[i];
  }

  // Output
  for (int i = 0; i < 7; i++) {
    printf ("%d ", ins_array[i]);
  }
  putchar ('\n');

  return 0;
}
