#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef bool
#define bool _Bool
#endif
#ifndef true
#define true 1
#endif
#ifndef false
#define false 0
#endif

#define BUFSIZE 512
#define BUFSIZE_SCANF "511"

struct _Student {
  char *name;
  int id;
  double gpa;
};
typedef struct _Student student;

// I did not write these prototypes.
bool checkID (student *list, int listLength, student *newstud);
bool checkGPA (student *newstud);
void free_student (student *s);

int main (void)
{
  student students[BUFSIZE] = {0};
  student stutemp = {0};
  int stucount = 0; // Actual length of students
  int r = 0;

  // Input loop
  for (stucount = 0; stucount < BUFSIZE; stucount++) {
    printf ("Please input record #%d (Name, ID, GPA):\n", stucount);

    // A temporary student element is used.
    // Values are moved to the real position after validation.

    // Allocate memory for name
    stutemp.name = malloc (BUFSIZE);
    if (!stutemp.name) {
      puts ("** Memory allocation error, aborting.");
      // Free allocated heap memory before exiting...
      for (int m = 0; m <= stucount; m++) {
        free_student (&students[m]);
      }
      abort ();
    }

    // Read
    r = scanf ("%" BUFSIZE_SCANF "s %d %lf", stutemp.name, &stutemp.id, &stutemp.gpa);
    if (r != 3) {
      puts ("** Encounter error while reading... exiting.");
      // Free allocated heap memory before exiting...
      for (int m = 0; m <= stucount; m++) {
        free_student (&students[m]);
      }
      return 1;
    }

    // Check
    // "0" 0 0 means the end of input
    if (strncmp (stutemp.name, "0", BUFSIZE) == 0 && stutemp.id == 0 && stutemp.gpa == 0) {
      // Before break, prevent memory leak...
      free (stutemp.name);
      break;
    }
    if (checkID (students, stucount, &stutemp)) {
      if (checkGPA (&stutemp)) {
        // Move stutemp into students[i]
        students[stucount].name = stutemp.name;
        students[stucount].id   = stutemp.id;
        students[stucount].gpa  = stutemp.gpa;
      } else {
        puts ("Error: Invalid GPA.");
        --stucount;
        // NOTE: As error happens, the allocated stutemp.name should be free'd
        if (stutemp.name) {
          free (stutemp.name);
        }
      }
    } else {
      puts ("Error: Student ID already exists.");
      --stucount;
      // NOTE: As error happens, the allocated stutemp.name should be free'd
      if (stutemp.name) {
        free (stutemp.name);
      }
    }

    // Clear stutemp before the next round
    // NOTE: DO NOT FREE stutemp.name! It was assigned (or was already free'd).
    stutemp.name = NULL;
    stutemp.id = 0;
    stutemp.gpa = 0;

  } // for (stucount = 0; stucount < BUFSIZE; stucount++)

  // Display
  puts ("\nName\tID\tGPA");
  for (int i = 0; i < stucount; i++) {
    printf ("%s\t%d\t%g\n", students[i].name, students[i].id, students[i].gpa);
  }

  return 0;
}

void free_student (student *s)
{
  if (s->name) {
    free (s->name);
    s->name = NULL;
  }
  s->id = 0;
  s->gpa = 0;
}

bool checkID (student *list, int listLength, student *newstud)
{
  for (int i = 0; i < listLength; i++) {
    if (newstud->id == list[i].id)
      return false;
  }

  return true;
}

bool checkGPA (student *newstud)
{
  if (newstud->gpa <= 0 || newstud->gpa > 4)
    return false;
  return true;
}
