//
#include <stdio.h>
// main()
int main (void)
{
  // int i, j = 5;
  int i = 0, j = 5;
  char ch;
  float f;
  // scanf("%c", ch);
  scanf("%c", &ch);
  printf("the ASCII code of '%c' is %d\n", ch, ch);
  printf("the value of i is %d\n", i);
  i = ch;
  printf("the value of i is %d\n", i);
}

/**
 * Q: When you build this program, what are the errors there?
 * A: Build using GNU GCC 7.2.0 (gcc 1.c):
 *      "1.c:11:1: error: expected ';' before '}' token"
 *
 * Q: After you fix the errors and re-build the project, are there warnings? Why?
 * A: Yes there are:
 *    1. 1.c:1:1: warning: return type defaults to 'int'
 *    2. 1.c:6:3: warning: implicit declaration of function 'scanf'
 *    3. 1.c:7:3: warning: implicit declaration of function 'printf'
 *    Because:
 *    1. Since C89 return type of a function should be declared; otherwise the
 *       comipler will fall back to K&R mode (assuming an int return value);
 *    2. 3. One should include stdio.h in order to use these functions. However,
 *          since libstdc is by default linked by linker, not including std*
 *          headers makes no errors.
 *
 * Q: Fix the program to remove errors and warnings (assume the initial value of i is 0).
 */
