#include <stdio.h>

// "the total number of integers will not exceed 50"
int a[50] = {0};

int main (void)
{
  int r = 0;
  int count = 0; // Count number of numbers input by user

  puts ("Please input some numbers (input 0 to end):"); /* exit):"); */
  for (count = 0; count < 50; count++) {
    r = scanf ("%d", &a[count]);
    if (r != 1) {
      puts ("Illegal input detected, exiting.");
      return 1;
    }
    if (a[count] == 0) {
      break;
    }
  }

  puts ("Among your inputs, the following are positive:");
  for (int i = 0; i < count; i++) {
    if (a[i] > 0) {
      printf("%d ", a[i]);
    }
  }
  putchar ('\n');

  return 0;
}
