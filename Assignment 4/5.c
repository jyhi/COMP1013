#include <stdio.h>

/**
 * a_n = 2a_{n - 1} + 1, a_1 = 2
 *
 * @param index subscript index
 * @return a_index
 */
int a (int index);

int main (void)
{
  printf ("a_16 = %d\n", a (16));
  return 0;
}

int a (int index)
{
  if (index <= 1)
    return 2;
  else
    return a (index - 1) * 2 + 1;
}
