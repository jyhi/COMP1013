#include <stdio.h>
#include <ctype.h>

int main (void)
{
  char c = '\0';
  int r = 0;

  r = scanf ("%c", &c);
  if (r != 1) {
    return 255;
  }

  if (isdigit (c)) {
    printf ("%c is a digit.\n", c);
  } else {
    if (isalpha (c)) {
      printf ("%c is an English letter.\n", c);
    } else {
      printf ("%c is not a digit nor an English letter.\n", c);
    }
  }

  return 0;
}
