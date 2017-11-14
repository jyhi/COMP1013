#include <stdio.h>

#define BUFSIZE 4096

// These 2 macros change something into a string.
// https://stackoverflow.com/questions/25410690/scanf-variable-length-specifier
#define _STR(s) #s
#define STR(s) _STR(s)

/**
 * Calculate length of str.
 *
 * @param str [in] String to count, must end up with NUL.
 * @return Length of str.
 */
size_t t3_strlen (const char *restrict str)
{
  size_t length = 0;

  if (!str)
    return 0;

  for (int i = 0; str[i] != '\0'; i++)
    length++;

  return length;
}

int stringCompare (const char *restrict str1, const char *restrict str2, const size_t size1, const size_t size2)
{
  if (!str1 || !str2)
    return 0;

  // Sanity Check
  // if (t3_strlen (str1) != size1 || t3_strlen (str2) != size2) {
  //   fprintf (stderr, "*** %s: %d: String length mismatch.\n", __func__, __LINE__);
  //   abort ();
  // }

  // Strings with inequal sizes are certainly not the same.
  if (size1 != size2)
    return 0; // False

  for (size_t i = 0; i < size1; i++) {
    if (str1[i] != str2[i])
      return 0; // False
  }

  return 1;
}

int main (void)
{
  char str1[BUFSIZE] = {0}, str2[BUFSIZE] = {0};
  int r = 0;

  puts ("Please input the first string:");
  // if (!fgets (str1, BUFSIZE, stdin)) {
  r = scanf ("%" STR(BUFSIZE) "[^\n]", str1);
  if (r != 1) {
    puts ("Read Error.");
    return 1;
  }

  // Flush stdin
  while ((r = getchar ()) && r != '\r' && r != '\n' && r != EOF) {}

  puts ("Please input the second string:");
  // if (!fgets (str2, BUFSIZE, stdin)) {
  r = scanf ("%" STR(BUFSIZE) "[^\n]", str2);
  if (r != 1) {
    puts ("Read Error.");
    return 1;
  }

  printf (
    "The two strings %s the same.\n",
    stringCompare (str1, str2, t3_strlen (str1), t3_strlen (str2)) ? "are" : "are not"
  );

  return 0;
}
