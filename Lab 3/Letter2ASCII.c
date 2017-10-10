#include <stdio.h>

int main (void)
{
  char c = '\0';

  puts ("Please input an English letter:");
  scanf ("%c", &c);
  printf (
    "\"%c\" and its neightbors in ASCII:\n"
    "%d\t%d\t%d\n"
    "%c\t%c\t%c\n",
    c,
    (int)c - 1, (int)c, (int)c + 1,
    c - 1, c, c + 1
  );

  return 0;
}
