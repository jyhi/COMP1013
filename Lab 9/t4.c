#include <stdio.h>
#include <string.h>

#define BUFSIZE 4096

#define _STR(s) #s
#define STR(s) _STR(s)

/**
 * Check if substr is a substring of str.
 *
 * @param str    [in] String to be searched.
 * @param substr [in] String to be searched for in str.
 * @return 0 if substr is not in str, 1 otherwise.
 */
int is_substr (const char *restrict str, const char *restrict substr)
{
  if (!str || !substr)
    return 0;

  for (size_t i = 0; i < strlen (str); i++) {
    if (str[i] == substr[0]) {
      // Begin a comparison round
      for (size_t j = 0; j < strlen (substr); j++) {
        if (str[i + j] != substr[j])
          // Matching failed; we should immediately start a next round.
          goto brk;
      }

      // Eventually if the above round completes, then substr is in str.
      return 1;
    }
brk:
  // t4.c:23:1: error: label at end of compound statement
  //  brk:
  //  ^~~
  ;
  }

  return 0;
  // return strstr (str, substr) ? 1 : 0;
}

int main (void)
{
  char str1[BUFSIZE] = {0};
  char str2[BUFSIZE] = {0};
  int r = 0;

  puts ("Please input the first string:");
  r = scanf ("%" STR(BUFSIZE) "[^\n]", str1);
  if (r != 1) {
    puts ("Invalid input.");
    return 1;
  }

  // fflush (stdin)
  while ((r = getchar()) && !(r != '\n' || r != '\r' || r != EOF)) {}

  puts ("Please input the second string:");
  r = scanf ("%" STR(BUFSIZE) "[^\n]", str2);
  if (r != 1) {
    puts ("Invalid input.");
    return 1;
  }

  printf ("The first string %s a substring of the second.\n", is_substr (str2, str1) ? "is" : "is not");

  return 0;
}
