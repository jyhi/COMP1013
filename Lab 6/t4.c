#include <stdio.h>

int main (void)
{
  int nline = 0;
  int r = 0;

  printf ("How many line shall we draw? ");
  r = scanf ("%d", &nline);
  if (r != 1) {
    puts ("Illegal input.");
    return 1;
  }

  for (int row = 0; row < nline; row++) {
    int to_print_asterisk = row * 2 + 1; // Row starts at 0
    int to_print_blank = (((nline - 1) * 2 + 1) - to_print_asterisk) / 2 + 1; // Per requirement (???)

    for (int i = 0; i < to_print_blank; i++) {
      printf (" ");
    }
    for (int i = 0; i < to_print_asterisk; i++) {
      printf ("*");
    }

    printf ("\n");
  }

  return 0;
}
