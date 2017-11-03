#include <stdio.h>

#define BUFSIZE 4096

int main (void)
{
  char buf[BUFSIZE] = {0};
  int counter = 0;

  if (!fgets (buf, BUFSIZE, stdin)) {
    puts ("** Fatal error: buffer overflow.");
    return 1;
  }

  for (char *ptr_to_read = buf;
       *ptr_to_read != '\0' && *ptr_to_read != '\n' && *ptr_to_read != '\r';
       ptr_to_read++) {
    if (*ptr_to_read == 'a') counter++;
  }

  printf("%d\n", counter);
  return 0;
}
