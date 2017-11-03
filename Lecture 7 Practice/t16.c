#include <stdio.h>

// static const char *pyramid = "\
// *\n\
// * *\n\
// * * *\n\
// * * * *\n\
// * * * * *\n\
// * * * * * *\n\
// * * * * * * *\n\
// * * * * * * * *\n\
// * * * * * * * * *\n\
// * * * * * * * * * *";

int main (void)
{
  // for (int i = 0; i < 1; i++) {
  //   for (int j = 0; j < 1; j++) {
  //     puts (pyramid);
  //   }
  // }

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j <= i; j++) {
      printf ("* ");
    }
    printf ("\n");
  }

  return 0;
}
