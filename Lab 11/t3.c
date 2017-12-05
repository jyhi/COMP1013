#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 512

/* Emmm */
#ifndef bool
#define bool _Bool
#endif
#ifndef true
#define true 1
#endif
#ifndef false
#define false 0
#endif

/* Emmm... */
static const char *bsod = "\
A problem has been detected and this program has been shut down to prevent damage to your computer.\n\
\n\
If this is the first time you've seen this Stop error screen, restart this program. If this screen appears again, follow these steps:\n\
\n\
Check to be sure you have input correct date. If a date is out of range, correct the date or check with the calendar for your brain. Try hit yourself.\n\
\n\
Check with your compiler for any bug fixes. Get rid of optimization options such as -Ofast or /fp:fast. If you need to use GDB to debug, execute 'gdb' with the executable file name, input 'b main' to set a brakepoint, and then input 'r' to start.\n\
\n\
Technical information:\n\
\n\
*** STOP: 0x00000001 (0x80000003, 0x805c49b8, 0xf7a172b4, 0xf7a16fb0)";

/**
 * Date.
 */
struct Date {
  int year;  //< Year
  int month; //< Month
  int day;   //< Day
};

/**
 * Given the date, return the day of the week.
 *
 * Algorithm is based on the Zeller's congruence.
 * See: https://en.wikipedia.org/wiki/Zeller%27s_congruence
 *
 * @param date [in]  Date to be calculated
 * @param wday [out] Name of the day of week, as null-terminated string. NOTE
 *                   that this must not be NULL, and should be long enough to
 *                   contain the week name strings.
 * @return true if the operation successed, false if the date is invalid.
 */
static bool dayOfWeek (struct Date date, char *wday);

int main (void)
{
  struct Date date = {0, 0, 0};
  int r = 0;

  puts ("Please input Y M D:");
  r = scanf ("%d %d %d", &(date.year), &(date.month), &(date.day));
  if (r != 3) {
    puts ("Input error.");
    return 1;
  }

  char *week = malloc (512);
  if (!week)
    abort ();

  if (dayOfWeek (date, week)) {
    printf ("%d/%d/%d is %s.\n", date.year, date.month, date.day, week);
  } else {
    puts (bsod);
  }

  return 0;
}

static bool dayOfWeek (struct Date date, char *wday)
{
  if (!wday)
    return false;

  // Do boundary check
  if (date.year <= 0)
    return false;
  if (date.month < 1 || date.month > 12)
    return false;
  // The formula only supports the Gregorian calendar (starts at Oct 15, 1582).
  if (date.year <= 1582 && date.month <= 10 && date.day <= 15)
    fprintf (stderr, "** Warning: date before Gregorian calendar will cause inaccurate result!\n");

  /* The optimized Zeller's congruence formula (for the Gregorian calendar):
   *
   *   w = (5c + |c / 4| + y + |y / 4| + |13(m + 1) / 5| + d) % 7
   *
   * Where:
   *   - w is the day of the week (0 = Saturday, 1 = Sunday, 2 = Monday, ..., 6 = Friday)
   *   - c is the zero-based century (year / 100)
   *   - y is the year of the century (year % 100)
   *   - m is the month (3 = March, 4 = April, 5 = May, ..., 14 = February)
   *   - d is the day of the month
   *
   * "Optimized" means, compared to the original formula, this formula will not
   * give negative number as the day of week. For details, see:
   * https://en.wikipedia.org/wiki/Zeller%27s_congruence#Implementation_in_software
   */
  static int days_of_month[] = {31, 0 /* Later */, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (date.year % 400 || (date.year % 4 && !(date.year % 100))) {
    days_of_month[1] = 29;
  } else {
    days_of_month[1] = 28;
  }

  // Do boundary check again (for days)
  if (date.day < 1 || date.day > days_of_month[date.month - 1])
    return false;

  int c = date.year / 100;
  int y = date.year % 100;
  int m = date.month < 3 ? date.month + 12 : date.month;
  int d = date.day;

  // Do boundary check again and again
  if (y < 0 || y > 99)
    return false;
  if (m < 3 || m > 14)
    return false;

  int w = (5 * c + c / 4 + y + y / 4 + 13 * (m + 1) / 5 + d) % 7;

  switch (w) {
    case 0:
      if (!strcpy (wday, "Saturday"))
        goto wday_strcpy_error;
      break;
    case 1:
      if (!strcpy (wday, "Sunday"))
        goto wday_strcpy_error;
      break;
    case 2:
      if (!strcpy (wday, "Monday"))
        goto wday_strcpy_error;
      break;
    case 3:
      if (!strcpy (wday, "Tuesday"))
        goto wday_strcpy_error;
      break;
    case 4:
      if (!strcpy (wday, "Wednesday"))
        goto wday_strcpy_error;
      break;
    case 5:
      if (!strcpy (wday, "Thursday"))
        goto wday_strcpy_error;
      break;
    case 6:
      if (!strcpy (wday, "Friday"))
        goto wday_strcpy_error;
      break;
    default:
      // Something happened.
      fprintf (stderr, "** Internal error at %s in %s:%d", __FILE__, __func__, __LINE__);
      return false;
      break;
  }

  return true;

wday_strcpy_error:
  fprintf (stderr, "** Error while copying week string...");
  return false;
}
