#include <stdio.h>
#include <string.h>

#define BUFSIZE 4096

/**
 * Calculate length of str.
 *
 * @param str [in] String to count, must end up with NUL.
 * @return Length of str.
 */
size_t t2_strlen (const char *restrict str)
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
  char b[BUFSIZE] = {0};
  char *ptr_to_read = NULL;
  int count = 0;

  puts ("Please input a line:");
  // if (!gets (a)) {
  if (!fgets (a, BUFSIZE, stdin)) {
    if (feof(stdin))
      goto out;

    puts ("** Error encounted while reading a string.");
    return 1;
  }

  // Goto the position of first word
  for (ptr_to_read = a;
       *ptr_to_read != '\0' && (*ptr_to_read == ' ' || *ptr_to_read == '\n' || *ptr_to_read == '\r');
       ptr_to_read++) {}

  // Count word length
  for (count = 0;
       !(*(ptr_to_read + count) == '\0' || *(ptr_to_read + count) == ' ' ||
         *(ptr_to_read + count) == '\n' || *(ptr_to_read + count) == '\r');
       count++) {}

  // Use memcpy per requirement.
  if (!memcpy (b, ptr_to_read, count)) {
    puts ("** Error while copying the word.");
    return 1;
  }

out:
  printf ("The first word is: %s\n", b);
  return 0;
}
