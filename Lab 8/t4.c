#include <stdio.h>

#define BUFSIZE 4096

// These 2 macros change something into a string.
// https://stackoverflow.com/questions/25410690/scanf-variable-length-specifier
#define _STR(s) #s
#define STR(s) _STR(s)

/**
 * Judge if ch is a digit in ASCII.
 *
 * @param ch [in] The character to judge.
 * @return 0 If ch is not a digit, otherwise 1.
 */
int t4_is_digit_ascii (int ch)
{
  if (ch >= '0' && ch <= '9')
    return 1; // True

  return 0; // False
}

/**
 * Convert a character into an integer.
 *
 * This function does not perform a conversion if ch is not a digit.
 *
 * @param ch [in] Character to convert.
 * @return The converted integer.
 */
int char2int (int ch)
{
  if (ch >= '0' && ch <= '9')
    return ch - '0';

  return ch;
}

/**
 * Calculate length of str.
 *
 * @param str [in] String to count, must end up with NUL.
 * @return Length of str.
 */
size_t t4_strlen (const char *restrict str)
{
  size_t length = 0;

  if (!str)
    return 0;

  for (int i = 0; str[i] != '\0'; i++)
    length++;

  return length;
}

/**
 * Convert a string into an integer.
 *
 * This function breaks once it meets a non-digit number.
 *
 * @param str [in] String to convert, must end up with NUL.
 * @return The converted integer.
 * @see t4_is_digit_ascii
 */
int str2int (const char *restrict str, const size_t length)
{
  if (!str)
    return 0;

  // Sanity Check
  // if (t4_strlen (str) != length) {
  //   fprintf (stderr, "*** %s: %d: String length mismatch.\n", __func__, __LINE__);
  //   abort ();
  // }

  size_t first_number_pos = 0;
  unsigned base = 1;
  int ret = 0;

  for (size_t i = 0; i < length; i++) {
    if (t4_is_digit_ascii (str[i])) {
      first_number_pos++;
    } else {
      break;
    }
  }

  for (int i = first_number_pos - 1; i >= 0; i--, base *= 10) {
    ret += base * char2int(str[i]);
  }

  return ret;
}

int main (void)
{
  char input[BUFSIZE] = {0};
  int r = 0;

  r = scanf ("%" STR(BUFSIZE) "[^\n]", input);
  if (r != 1) {
    puts ("Invalid input.");
    return 1;
  }

  printf ("%d\n", str2int (input, t4_strlen (input)));
  return 0;
}
