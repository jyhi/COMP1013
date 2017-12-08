#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 4096
#define BUFSIZE_SCANF "4095"

int main (void)
{
  char str[BUFSIZE] = {0};
  int r = 0;

  puts ("Please enter a sentence in English:");
  r = scanf ("%" BUFSIZE_SCANF "[^\n]", str);
  if (r != 1) {
    puts ("Read error.");
    return 1;
  }

  // Search for the first non-blank charaacter after a blank character:
  //   "   good good study day        day     up"
  //      ~^   ~^   ~^    ~^         ~^      ~^
  int is_prev_blank = 1;
  for (char *ptr_to_read = str; *ptr_to_read != '\0'; ptr_to_read++) {
    if (*ptr_to_read == ' ') {
      is_prev_blank = 1;
    } else {
      if (is_prev_blank == 1) {
        *ptr_to_read = toupper (*ptr_to_read);
      }
      is_prev_blank = 0;
    }
  }

  puts (str);

  return 0;
}
