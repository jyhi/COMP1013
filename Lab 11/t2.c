#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 256
#define BUFSIZE_SCANF "255"

// enum Major {
//   // TODO
// }

/**
 * A student.
 */
struct _Student {
  char *name; //< Name of the student
  int score;  //< Score of the student
  // enum Major major;
  char *major; //< Major of the student
};
typedef struct _Student Student;

/**
 * Given a student s, free the memory allocated.
 *
 * @param s [in] The Student s to be free'd
 */
static void free_student (Student *s)
{
  if (s->name) {
    free (s->name);
    s->name = NULL;
  }
  if (s->major) {
    free (s->major);
    s->major = NULL;
  }
  s->score = 0;
}

static void print_student_info (Student s)
{
  printf ("%s\t%d\t%s\n", s.major, s.score, s.name);
}

int main (void)
{
  int n = 0;
  int r = 0;

  puts ("How many students to record?");
  r = scanf ("%d", &n);
  if (r != 1) {
    puts ("Invalid input.");
    return 1;
  }

  if (n <= 0) {
    puts ("Invalid number of students... exiting.");
    return 1;
  }

  Student *students = malloc (sizeof (Student) * n);
  if (!students) {
    fprintf(
      stderr,
      "** Memory allocation failed at %s (%s:%d).\n",
      __func__, __FILE__, __LINE__
    );
    abort();
  }

  for (int i = 0; i < n; i++) {
    printf ("----- Recording the %dth student...\n", i + 1);

    printf ("Name: ");
    students[i].name = malloc (BUFSIZE);
    if (!students[i].name) {
      puts ("** Memory allocation error, aborting.");
      // Free allocated heap memory before exiting...
      for (int m = 0; m <= i; m++) {
        free_student (&students[m]);
      }
      free(students);
      abort ();
    }
    r = scanf (" %" BUFSIZE_SCANF "[^\n]", students[i].name);
    if (r != 1) {
      puts ("** Encounter error while reading... exiting.");
      // Free allocated heap memory before exiting...
      for (int m = 0; m <= i; m++) {
        free_student (&students[m]);
      }
      free(students);
      return 1;
    }

    printf ("Score: ");
    r = scanf ("%d", &students[i].score);
    if (r != 1) {
      puts ("** Read error, expect an integer... exiting.");
      // Free allocated heap memory before exiting...
      for (int m = 0; m <= i; m++) {
        free_student (&students[m]);
      }
      free(students);
      return 1;
    }

    printf ("Major: ");
    students[i].major = malloc (BUFSIZE);
    if (!students[i].major) {
      puts ("** Memory allocation error, aborting.");
      // Free allocated heap memory before exiting...
      for (int m = 0; m <= i; m++) {
        free_student (&students[m]);
      }
      free(students);
      abort ();
    }
    r = scanf (" %" BUFSIZE_SCANF "[^\n]", students[i].major);
    if (r != 1) {
      puts ("** Encounter error while reading... exiting.");
      // Free allocated heap memory before exiting...
      for (int m = 0; m <= i; m++) {
        free_student (&students[m]);
      }
      free(students);
      return 1;
    }
  } // for (int i = 0; i < n; i++)

  puts ("\n===== Now printing student info...");
  puts ("Major\tScore\tName");
  for (int i = 0; i < n; i++) {
    print_student_info (students[i]);
  }

  // Free allocated heap memory before exiting...
  for (int m = 0; m <= n; m++) {
    free_student (&students[m]);
  }
  free(students);

  return 0;
}
