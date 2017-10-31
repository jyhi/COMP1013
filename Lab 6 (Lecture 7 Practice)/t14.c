#include <stdio.h>

int main ()
{
  int mycard = 3;
  int guess = 0;

  for (;;) {
    printf ("Guess my card: ");
    scanf ("%d", &guess);
    if (guess == mycard) {
      printf ("Good guess!\n");
      // break;

      // Avoid using break per requirement.
      // exit(0);
      goto quit;
    } else {
      printf ("Try again.\n");
    }
  }

quit:
  return 0;
}
