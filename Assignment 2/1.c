#include <stdio.h>

#define LINES 6

int main (void)
{
  // Use loop per requirement.
  for (int i = 0; i < LINES; i++) {
    for (int j = i; j < LINES - 1; j++) {
      printf("*#");
    }
    printf ("*\n");
  }

  return 0;
}
