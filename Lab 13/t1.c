#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 4096

int main (void)
{
  char *buf = NULL;
  unsigned count = 0;

  FILE *f = fopen ("list.txt", "r");
  if (!f)
    return 1;

  // On Linux you can make use of /dev/null (NO NEED)
  // FILE *devnull = fopen ("/dev/null", "w");
  // if (!devnull) {
    // Use limited length of buffer
    buf = (char *)malloc (BUFSIZE);
    if (!buf) {
      puts ("** Memory allocation failed.");
      abort ();
    }
  // }

  // while (fgets (devnull ? (char *)devnull : buf, BUFSIZE, f))
  while (fgets (buf, BUFSIZE, f))
    ++count;

  printf ("%d\n", count);

  if (buf)
    free (buf);

  return 0;
}
