#include <stdio.h>

static const int a[] =
  {-34, -33, -21, -13, -2, 3, 4, 6, 9, 12, 21, 23, 25, 32, 42, 48, 50};
static const int ALength = 17;

int binarySearch (const int *a, const int x, const int l, const int r)
{
  int pos = (l + r) / 2; // (l - r) / 2 + l

  if (pos < l || pos > r)
    return -1;

  if (a[pos] == x) {
    return pos + 1;
  } else if (a[pos] > x) {
    return binarySearch (a, x, l, pos - 1);
  } else {
    return binarySearch (a, x, pos + 1, r);
  }
}

int main (void)
{
  int search = 0;
  int r = 0;
  puts ("Please input an integer:");
  r = scanf ("%d", &search);
  if (r != 1) {
    puts ("Invalid input.");
    return 1;
  }

  if ((r = binarySearch (a, search, 0, ALength - 1)) != -1) {
    printf ("%d's position in the array is: %d\n", search, r);
  } else {
    printf ("%d's not in the array\n", search);
  }

  return 0;
}
