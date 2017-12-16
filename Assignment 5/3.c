#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 64
#define BUFSIZE_SCANF "63"
#define STUDENTS_SIZE 20

struct Student {
  char name[BUFSIZE];
  int score;
};

int cb_sort_by_score_descending (const void *l, const void *r)
{
  struct Student *s1 = (struct Student *)l;
  struct Student *s2 = (struct Student *)r;

  // Descending order
  if (s1->score < s2->score)
    return 1;
  else if (s1->score > s2->score)
    return -1;

  return 0;
}

void sort (struct Student *stulist, const size_t len)
{
  // qsort makes my life easier
  qsort (stulist, len, sizeof (struct Student), cb_sort_by_score_descending);
}

int main (void)
{
  struct Student students[STUDENTS_SIZE] = {0};
  int count = 0; // Count actual number of students while reading input
  int r = 0;

  FILE *fp_student = fopen ("student.txt", "r");
  if (!fp_student) {
    puts ("Error: student.txt not found.");
    return 2;
  }

  for (count = 0; count < STUDENTS_SIZE && !feof (fp_student); count++) {
    r = fscanf (fp_student, "%" BUFSIZE_SCANF "s %d", students[count].name, &students[count].score);
    if (r != 2) {
      // EOF (-1) is expected.
      if (feof (fp_student))
        break;

      puts ("Read error.");
      fclose (fp_student);
      return 1;
    }
  }

  fclose (fp_student);
  fp_student = NULL;

  sort (students, count);

  FILE *fp_sorted = fopen ("sorted.txt", "w");
  if (!fp_sorted) {
    puts ("Error: cannot create sorted.txt for write.");
    fclose (fp_sorted);
    return 1;
  }

  for (int i = 0; i < count; i++) {
    fprintf (fp_sorted, "%s %d\n", students[i].name, students[i].score);
  }

  return 0;
}
