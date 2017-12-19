#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// DISCLAIMER: THIS IS ONLY A IN-CLASS ASSIGNMENT.
// DO NOT USE IN REALITY.

int main (void)
{
  char *password_charset = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; // Length: 62
  char *buf_password = NULL; // Buffer to store generated password
  FILE *dev_random = NULL;   // Random device, if usable
  FILE *fp_passwd = NULL;    // File to output password
  int length = 0;            // Length of password requested by user
  int r = 0;

  puts ("What is the length of your password?");
  r = scanf ("%d", &length);
  if (r != 1) {
    puts ("Illegal input.");
    return 1;
  }

  if (length < 1) {
    puts ("Too short.");
    return 1;
  }

  // Clear buf_password while allocating
  // NOTE: There must be at leat one NUL at the end of buf_password
  buf_password = calloc (sizeof (char), length + 1);
  if (!buf_password) {
    puts ("** Memory allocation failed.");
    abort ();
  }

  // On Linux /dev/urandom (unblocked) or /dev/random (blocked) should be used
  // to enhance security.
  dev_random = fopen ("/dev/urandom", "r");
  if (!dev_random)
    dev_random = fopen ("/dev/random", "r");
  // dev_urandom will be NULL if none of them exists.

  for (;;) {
    if (dev_random) {
      // Use random device
      for (int i = 0; i < length; i++) {
        // Round input into the charset
        buf_password[i] = password_charset[fgetc (dev_random) % 62];
      }
    } else {
      // Use pseudo-random number
      srand (time (NULL));
      for (int i = 0; i < length; i++) {
        buf_password[i] = password_charset[rand () % 62];
      }
    }

    printf ("Password suggestion: %s\n", buf_password);
    puts ("Use this password? (Y/n)");

    for (;;) {
      switch (getchar ()) {
        case 'Y': // fall through
        case 'y':
          // Save password suggestion in passwd.txt
          fp_passwd = fopen ("passwd.txt", "w");
          if (!fp_passwd) {
            puts ("** Failed to open passwd.txt for write.");
            goto quit;
          }

          r = fputs (buf_password, fp_passwd);
          if (r == EOF) {
            puts ("** Failed to write password into passwd.txt.");
            goto quit;
          }

          printf ("The following password is saved in passwd.txt: %s\n", buf_password);
          goto quit;

          break;
        case 'N': // fall through
        case 'n':
          // Retry
          goto ask_out;
          break;
        default:
          // Keep asking
          break;
      }
    }
ask_out:
    ;
  }

quit:
  if (buf_password)
    free (buf_password);
  if (dev_random) {
    r = fclose (dev_random);
    if (r == EOF)
      puts ("** Warning: random device cannot be closed.");
  }
  if (fp_passwd) {
    r = fclose (fp_passwd);
    if (r == EOF)
      puts ("** Warning: passwd.txt cannot be closed.");
  }

  return 0;
}
