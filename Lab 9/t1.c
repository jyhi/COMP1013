#include <stdio.h>

#define BUFSIZE 4096

/**
 * Calculate length of str.
 *
 * @param str [in] String to count, must end up with NUL.
 * @return Length of str.
 */
size_t t1_strlen (const char *restrict str)
{
  size_t length = 0;

  if (!str)
    return 0;

  for (int i = 0; str[i] != '\0'; i++)
    length++;

  return length;
}

int main (void)
{
  char a[BUFSIZE] = {0};
  int counter = 0;
  int is_prev_blank = 1;

  puts ("Please input a line:");
  // if (!gets (a)) {
  if (!fgets (a, BUFSIZE, stdin)) {
    if (feof(stdin))
      goto out;

    puts ("** Error encounted while reading a string.");
    return 1;
  }

  if (t1_strlen (a) == 0)
    goto out;

  for (int i = 0; a[i] != '\0'; i++) {
    // Count the first non-blank charaacter after a blank character:
    //   "   good good study day        day     up'\n'"
    //      ~^   ~^   ~^    ~^         ~^      ~^       => 6 Words
    if (a[i] == '\0' || a[i] == ' ' || a[i] == '\n' || a[i] == '\r') {
      // Blank character
      is_prev_blank = 1;
    } else {
      // Not a blank character
      if (is_prev_blank)
        counter++;
      is_prev_blank = 0;
    }
  }

out:
  printf ("There are %d words in the line.\n", counter);
  return 0;
}
