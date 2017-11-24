#include <stdio.h>
#include <ctype.h>

// NOTE:
// 1. In scanf, the field width should be 1 character less than the actual
//    buffer size since space for NUL('\0') should be reserved.
// 2. We cannot stringify an expression. Thus, a SCANBUF is defined as a string
//    with number 4096 - 1 for scanf's use. (FIXME)
#define BUFSIZE 4096
#define SCANBUF "4095"

#define STR(s) _STR(s)
#define _STR(s) #s

int main (void)
{
  char input[BUFSIZE] = {0};
  char *p_read = input;
  int r = 0;

  r = scanf ("%" SCANBUF "s", input);
  if (r != 1) {
    puts ("Read error.");
    return 1;
  }

  for (; *p_read != '\0'; p_read++) {
    if (isalpha(*p_read))
      putchar (*p_read);
  }
  putchar ('\n');

  return 0;
}
