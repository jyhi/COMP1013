#include <stdio.h>

int is_prime (const int input);

int main (void)
{
  int input = 0;
  int r;

  for (;;) {
    printf ("Please input a positive integer (input 0 to exit): ");
    r = scanf ("%d", &input);
    if (r != 1) {
      puts ("Illegal input.");
      // Before continue, flush stdin. XXX: Reuse `r`
      while ((r = getchar()) && r != '\n' && r != EOF) {}
      continue;
    }

    if (input == 0) {
      return 0;
    }

    printf("%d %s a prime.\n", input, (is_prime(input) ? "is" : "is not"));
  }

  return 0;
}

int is_prime (const int input)
{
  // 0 is not considered as a prime
  // https://math.stackexchange.com/questions/539174/is-zero-a-prime-number
  if (input <= 0) {
    puts ("** Meet negative number or 0, expect positive one.");
    return 0; // False
  }

  for (int i = 2; i < input; ++i) {
    if (input % i == 0) {
      return 0; // False
    }
  }

  return 1; // True
}
