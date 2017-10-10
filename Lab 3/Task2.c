#include <stdio.h>

int main (void)
{
  int a = 0, b = 0;

  puts ("Input 2 integers:");
  scanf ("%d %d", &a, &b);

  if (b == 0) {
    puts ("b can't be 0.");
    return 1;
  }

  printf (
    // FIXME: Overflow not handled
    "%d+%d=%d\n"
    "%d-%d=%d\n"
    "%d*%d=%d\n"
    "%d/%d=%d\n"
    "%d%%%d=%d\n",
    a, b, a + b,
    a, b, a - b,
    a, b, a * b,
    a, b, a / b,
    a, b, a % b
  );

  return 0;
}
