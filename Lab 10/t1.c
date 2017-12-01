#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define BUFSIZE 4096
#define BUFSIZE_SCANF "4095"

int power (const int base, const int exponent)
{
  int ret = 1;
  for (int i = 0; i < exponent; i++) {
    ret *= base;
  }
  return ret;
}

int toDecimal (const char *restrict str)
{
  if (!str)
    return 0;

  int ret = 0;
  int exponent = 0;

  for (int i = strlen (str) - 1; i >= 0 && exponent <= INT_MAX; i--, exponent++) {
    ret += (str[i] - '0') * power (2, exponent);
  }

  return ret;
}

int main (void)
{
  int r = 0;
  char *buf = malloc (BUFSIZE);
  if (!buf)
    abort ();

  for (;;) {
    puts ("Please input a binary number:");
    r = scanf ("%" BUFSIZE_SCANF "s", buf);
    if (r != 1) {
      puts ("Read error.");
      free (buf);
      return 1;
    }
    if (strcmp (buf, "0") == 0) {
      free (buf);
      return 0;
    }

    printf ("%s is %d in decimal.\n", buf, toDecimal (buf));
  }

  return 0;
}
