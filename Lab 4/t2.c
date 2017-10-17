#include <stdio.h>

int main (void)
{
  int a = 0, b = 0, c = 0;
  puts ("Please input three integers:");
  scanf ("%d %d %d", &a, &b, &c);
  printf (
    "Among %d, %d and %d, %d is the greatest.\n",
    a, b, c,
    a > c ? (a > b ? a : b) : (b > c ? b : c)
  );
  return 0;
}
