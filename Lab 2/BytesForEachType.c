#include <stdio.h>

int main (void)
{
  printf ("\
Number of bytes used to store a char type variable is %d\n\
Number of bytes used to store a short int type variable is %d\n\
Number of bytes used to store an int type variable is %d\n\
Number of bytes used to store a long int type variable is %d\n\
Number of bytes used to store a float type variable is %d\n\
Number of bytes used to store a double type variable is %d\n",
  sizeof (char), sizeof (short), sizeof (int), sizeof (long), sizeof (float), sizeof (double));

  return 0;
}
