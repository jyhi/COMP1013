#include <stdio.h>

int main (void)
{
  int height = 0, weight = 0;

  scanf ("%d %d", &height, &weight);

  if ((height - 105) > (weight + 20)) {
    puts ("You are too slim");
  } else {
    if (((weight - 10) < (height - 105)) && ((height - 105) <= (weight + 20))) {
      puts ("You are fit");
    } else {
      puts ("You are too fat");
    }
  }

  return 0;
}
