#include <stdio.h>

int main (void)
{
  int i = 0;
  int ret = 0;

  ret = scanf ("%d", &i);
  if (ret != 1) {
    return 255;
  }

  printf ("%s", i % 2 == 0 ? "Even\n" : "Odd\n");

  return 0;
}
