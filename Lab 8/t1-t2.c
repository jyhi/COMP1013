#include <stdio.h>

#define _____ float

_____ findBiggest (float a[], int n);
_____ findLowest (float *restrict a, const int n);

int main (void)
{
  float value[4] = {2.5, -4.75, 1.2, 3.67};
  float bigValue;
  float lowValue;
  // bigValue = findBiggest (____, ____);
  bigValue = findBiggest (value, 4);
  lowValue = findLowest (value, 4);
  // printf ("bigValue = %f\n", bigValue);
  printf ("bigValue = %f, lowValue = %f\n", bigValue, lowValue);
  return 0;
}

_____ findBiggest (float a[], int n)
{
  float biggest = 0.0;

  for (int i = 0; i < n; i++) {
    if (a[i] > biggest) {
      biggest = a[i];
    }
  }

  return biggest;
}

_____ findLowest (float *restrict a, const int n)
{
  float lowest = 0.0;

  for (int i = 0; i < n; i++) {
    if (lowest > a[i]) {
      lowest = a[i];
    }
  }

  return lowest;
}
