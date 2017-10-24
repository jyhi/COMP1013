#include <stdio.h>

int main (void)
{
  char gpa_alpha = '\0';

  // Error handling in below switch.
  // if (scanf ("%c", &gpa_alpha) != 1) {
  //   puts ("Illegal GPA.");
  //   return 255;
  // }
  scanf ("%c", &gpa_alpha);

  switch (gpa_alpha) {
    case 'A': // fall through
    case 'a':
      printf ("%.2f\n", 4.00);
      break;
    case 'B': // fall through
    case 'b':
      printf ("%.2f\n", 3.00);
      break;
    case 'C': // fall through
    case 'c':
      printf ("%.2f\n", 2.00);
      break;
    case 'D': // fall through
    case 'd':
      printf ("%.2f\n", 1.00);
      break;
    case 'F': // fall through
    case 'f':
      printf ("%.2f\n", 0.00);
      break;
    default:
      puts ("Illegal GPA.");
      return 255;
      break;
  }

  return 0;
}
