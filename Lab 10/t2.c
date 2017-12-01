#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BUFSIZE 51

void toBinary (const int dec, char *bin)
{
  if (!bin)
    return;

  int n = dec;

  // Set 0
  if (!memset (bin, 0, BUFSIZE))
    abort ();

  for (int i = log2(n); i >= 0 && n > 0; i--, n /= 2) {
    bin[i] = n % 2 + '0';
  }
}

int main (void)
{
  int input = 0;
  int r = 0;
  char bin[BUFSIZE] = {0};

  for (;;) {
    puts ("Please input a decimal number:");
    r = scanf ("%d", &input);
    if (r != 1) {
      puts ("Input error.");
      while ((r = getchar ()) && r != EOF && r != '\n') {}
      continue;
    }
    if (input == 0)
      return 0;

    toBinary (input, bin);

    printf ("%s\n", bin);
  }

  return 0;
}
