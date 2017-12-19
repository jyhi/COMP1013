// I DID NOT WRITE THIS CODE
// ANSWERS ARE AT BELOW
#include <stdio.h>
#include <stdlib.h>

struct stuRec {
  char name[20];
  int id;
  char gender;
};

int main ()
{
  struct stuRec *p;

  // 1. Is the memory dynamically allocated or statically allocated?
  // A: Dynamically allocated on heap.

  p = (struct stuRec*)malloc (sizeof (struct stuRec));
  if (p) {
    printf ("please input name, id and gender\n");

    // 2. What %*c is used for?
    // A: A * between % and format specifier means skipping the read of the content
    //    (that is, not storing what it reads in somewhere).

    scanf ("%s%d%*c%c", p->name, &p->id, &p->gender);

    // 3. If %-10s is changed to %10s, what happened?
    // A: The name will be aligned to the right of the 10-character field, instead
    //    of %-10s's left-align.

    printf ("name:%10s,ID:%d,gender:%c\n", p->name, p->id, p->gender);

    // 4. Why do we need to add free (p)?
    // A: To prevent memory leak.

    free (p);
  }
return 0;
}
