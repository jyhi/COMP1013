#include <stdio.h>

int main (void)
{
  int matrix_a[4] = {0};
  int matrix_b[4] = {0};
  int r = 0;

  puts ("Please input matrix 1 (2*2):");
  for (int i = 0; i < 4; i++) {
    r = scanf ("%d", &matrix_a[i]);
    if (r != 1) {
      puts ("Read error.");
      return 1;
    }
  }

  puts ("Please input matrix 2 (2*2):");
  for (int i = 0; i < 4; i++) {
    r = scanf ("%d", &matrix_b[i]);
    if (r != 1) {
      puts ("Read error.");
      return 1;
    }
  }

  printf (
    "The SUM matrix is:\n%d\t%d\n%d\t%d\n",
    matrix_a[0] + matrix_b[0], matrix_a[1] + matrix_b[1],
    matrix_a[2] + matrix_b[2], matrix_a[3] + matrix_b[3]
  );

  return 0;
}
