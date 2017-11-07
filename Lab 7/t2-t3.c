#include <stdio.h>

#define BUFSIZE 4096

// These 2 macros change something into a string.
// https://stackoverflow.com/questions/25410690/scanf-variable-length-specifier
#define _STR(s) #s
#define STR(s) _STR(s)

/**
 * Converts the given character to lowercase according to the character
 * conversion rules in ASCII English alphabets.
 *
 * May have bugs.
 *
 * @param ch [in] The character to be converted.
 * @return The lowercase.
 * @see http://en.cppreference.com/w/c/string/byte/tolower
 */
int t2_ascii_tolower (int ch) // int tolower( int ch );
{
  if (!(((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z'))))
    return ch;

  if ((ch >= 'A') && (ch <= 'Z'))
    return ch + 32;

  return ch;
}

/**
 * Convert all characters in str to lowercase.
 *
 * This function depends on t2_ascii_tolower.
 *
 * @param str    [in] The string to be converted.
 * @param length [in] The length of str. This should not be other than the exact
 *                    length of str.
 * @see t2_ascii_tolower
 */
void str_tolower (char *restrict const str, const size_t length)
{
  for (size_t i = 0; i < length; i++) {
    // TODO: FIXME:
    // "If the value of ch is not representable as unsigned char and does not
    // equal EOF, the behavior is undefined."
    // http://en.cppreference.com/w/c/string/byte/tolowers
    // str[i] = tolower (str[i]);
    str[i] = t2_ascii_tolower (str[i]); // XXX
  }
}

/**
 * To prevent compiler warnings. May have bugs.
 *
 * @param str [in] String to count, must end up with NUL.
 * @return Length of str.
 */
size_t t2_strlen (const char *restrict str)
{
  size_t length = 0;

  if (str == NULL)
    return 0;

  for (int i = 0; str[i] != '\0'; i++) {
    length++;
  }

  return length;
}

/**
 * Judge whether str is a Palindrome or not.
 *
 * @param str    [in] The string to be judged.
 * @param length [in] The length of str. This should not be other than the exact
 *                    length of str.
 * @return 0 If str is not a Palindrome, others if it is.
 */
int is_palindrome (const char *restrict str, const size_t length)
{
  for (size_t p = 0; p < length / 2; p++) {
    if (str[p] != str[length - 1 - p])
      return 0; // False
  }

  return 1; // True
}

int main (void)
{
  char buf[BUFSIZE] = {0}; // Line Buffer
  size_t str_actual_length = 0;
  int r = 0;

  puts ("Please input a lower-case English word:");
  //if (!fgets(buf, BUFSIZE, stdin)) {
  r = scanf ("%" STR(BUFSIZE) "s", buf);
  if (r != 1) {
    puts ("Read error.");
    return 1;
  }

  str_actual_length = t2_strlen (buf);

  // In Task 3 you need to make the input case insensitive.
  str_tolower (buf, str_actual_length);

  printf("It's %s palindrome.\n", is_palindrome(buf, str_actual_length) ? "a" : "not a");
  return 0;
}
