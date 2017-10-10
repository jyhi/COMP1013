#include <stdio.h>

int main (void)
{
	int percentage, x;
	char ch1, ch2;
	scanf ("%d%c%c%d", &percentage, &ch1, &ch2, &x);
	printf ("%d%% %c%c %d is %f\n", percentage, ch1, ch2, x, 1.0 * x * percentage / 100);
  return 0;
}
