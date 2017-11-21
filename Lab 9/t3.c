#include <stdio.h>
#include <string.h>

#define BUFSIZE 4096

#define _STR(s) #s
#define STR(s) _STR(s)

void flush_stdin (void)
{
  int c = '\0';

  // NOTE: getchar will block stdin.
  while ((c = getchar()) && c != '\n' && c != EOF) {}
}

int main (void)
{
  char buf1[BUFSIZE] = {0};
  char buf2[BUFSIZE] = {0};
  int r = 0;

  for (;;) {
    // Always flush stdin before reading it.
    // flush_stdin ();

    // Round 1
    puts ("Please set your password:");
    r = scanf ("%" STR(BUFSIZE) "s", buf1);
    if (r != 1) {
      puts ("Illegal input.");
      return 1;
    }

    // Length >= 8
    if (strlen (buf1) < 8) {
      puts ("Password not long enough.");
      flush_stdin ();
      continue;
    }

    // Per requirement: use the first 20 characters.
    if (strlen (buf1) > 20) {
      buf1[20] = '\0';
    }

    // Always flush stdin before reading it.
    flush_stdin ();

    // Round 2
    puts ("Please confirm your password:");
    r = scanf ("%" STR(BUFSIZE) "s", buf2);
    if (r != 1) {
      puts ("Illegal input.");
      return 1;
    }

    // Per requirement: use the first 20 characters.
    if (strlen (buf2) > 20) {
      buf2[20] = '\0';
    }

    // Check if two inputs match
    if (memcmp (buf1, buf2, BUFSIZE) != 0) {
      puts ("Passwords don't match.");
      flush_stdin ();
      continue;
    } else {
      printf ("Your password \"%s\" is confirmed.\n", buf2);
      break;
    }
  }

  return 0;
}
