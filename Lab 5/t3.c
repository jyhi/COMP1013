#include <stdio.h>

const double XRate_US2EUR = 0.5;
const double XRate_US2RMB = 7.0;

int main (void)
{
  double usd = 0, result = 0;
  char selection = '\0';
  int r = 0; // RetVal

  puts ("Please input the amount of US dollars:");
  r = scanf ("%lf", &usd);
  if (r != 1) {
    puts ("Illegal number of US dollars.");
    return 255;
  }

  // this stdin very dirty
  while ((r = getchar()) && r != '\n' && r != EOF) {}

  puts ("Convert to Euro(E) or RMB(R)?");
  r = scanf ("%c", &selection);
  if (r != 1) {
    puts ("Illegal type of conversion.");
    return 255;
  }

  switch (selection) {
    case 'E': // fall through
    case 'e':
      result = usd * XRate_US2EUR;
      break;
    case 'R': // fall through
    case 'r':
      result = usd * XRate_US2RMB;
      break;
    default:
      // Not EUR nor RMB
      puts ("Wrong type of conversion, exiting.");
      return 1;
      break;
  }

  printf ("%g US dollars converts to %g %s.\n", usd, result, (selection == 'E' || selection == 'e') ? "euro" : "yuan");

  return 0;
}
