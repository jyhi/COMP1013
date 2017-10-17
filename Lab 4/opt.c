#include <stdio.h>

// #define BITEXTR(a,b) ((a)&1<<((b)-1)?1:0)

int main (void)
{
  unsigned int i = 0;
  puts ("Please input an integer between 0 to 15:");
  scanf ("%u", &i);

  // // this number very 4-bit
  // i &= 0xf;

  printf (
    "%u is %d%d%d%d in binary.\n",
    i,
    // BITEXTR(i, 4), BITEXTR(i, 3), BITEXTR(i, 2), BITEXTR(i, 1)
    (i & 8 ? 1 : 0), (i & 4 ? 1 : 0), (i & 2 ? 1 : 0), (i & 1 ? 1 : 0)
  );
  return 0;
}
