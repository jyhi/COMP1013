#include <stdio.h>
#include <string.h>

#define DATATYPE_INT    0
#define DATATYPE_DOUBLE 1
#define DATATYPE_STRING 2

int compare (void *p, void *q, int dataType);

int main (void)
{
  int i = 1, j = 1;
  printf ("%d\n", compare (&i, &j, DATATYPE_INT));
  double x = 1.22, y = 1.21;
  printf ("%d\n", compare (&x, &y, DATATYPE_DOUBLE));
  char *a = "Baby", *b = "Dragon";
  printf ("%d\n", compare (a, b, DATATYPE_STRING));
}

int compare (void *p, void *q, int dataType)
{
  switch (dataType) {
    case DATATYPE_INT:
      if (*(int *)p < *(int *)q) {
        return -1;
      } else if (*(int *)p > *(int *)q) {
        return 1;
      } else return 0;
      break;
    case DATATYPE_DOUBLE:
      if (*(double *)p < *(double *)q) {
        return -1;
      } else if (*(double *)p > *(double *)q) {
        return 1;
      } else return 0;
      break;
    case DATATYPE_STRING:
      return strcmp ((char *)p, (char *)q);
      break;
    default:
      return 0;
      break;
  }
}
