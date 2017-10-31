#include <stdio.h>

// void main () // It's 2017, my dear
int main (void)
{
  int sum = 0;
  int i = 1;

  for (; i <= 100; i++) {
    // if (i % 2 == 0) {
    //   continue;
    // }
    // sum = sum + i;

    // Avoid using continue per requirement.
    if (i % 2 != 0) {
      sum = sum + i;
    }
  }

  printf ("i = %d, sum = %d\n", i, sum);

  return 0;
}
