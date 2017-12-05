#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * A point.
 */
struct _Point {
  int x; //< X axis.
  int y; //< Y Axis.
};
typedef struct _Point Point;

/**
 * A line, consisting of 2 points.
 *
 * @see struct _Point
 */
struct _Line {
  struct _Point p1; //< Point 1.
  struct _Point p2; //< Point 2.
};
typedef struct _Line Line;

/**
 * A triangle, consisting of 3 points.
 *
 * @see struct _Point
 */
struct _Triangle {
  struct _Point p1; //< Point 1.
  struct _Point p2; //< Point 2.
  struct _Point p3; //< Point 3.
};
typedef struct _Triangle Triangle;

/**
 * Given a line, calculate its length.
 *
 * @param line [in] A line.
 * @return Length of line, in double.
 * @see Line
 */
static double length (Line line);

/**
 * Given a triangle, calculate its circumference.
 *
 * @param triangle [in] A triangle.
 * @return Circumference of triangle, in double.
 * @see Triangle
 */
static double circumference (Triangle triangle);

/**
 * Print point information to stdout.
 *
 * The format is: "Point: (x, y)".
 *
 * @param point [in] Point to be printed.
 */
static void printPoint (Point point);

/**
 * Print line information to stdout.
 *
 * The format is: "Line: (x1, y1) - (x2, y2) Length: len".
 *
 * @param line [in] Line to be printed.
 */
static void printLine (Line line);

/**
 * Print triangle information to stdout.
 *
 * The format is: "Triangle: (x1, y1) - (x2, y2) - (x3, y3) Circumference: c".
 *
 * @param triangle [in] Triangle to be printed.
 */
static void printTriangle (Triangle triangle);

int main (void)
{
  // Per requirement.
  Point p[6] = {
    {1, 5}, {2, 1}, {2, 7}, {4, 3}, {6, 8}, {8, 2}
  };
  Line l[4] = {
    {p[0], p[2]}, {p[3], p[4]}, {p[3], p[5]}, {p[4], p[5]}
  };
  Triangle t = {p[3], p[4], p[5]};

  for (int i = 0; i < 6; i++) {
    printPoint (p[i]);
  }
  for (int i = 0; i < 4; i++) {
    printLine (l[i]);
  }
  printTriangle (t);

  return 0;
}

static double length (Line line)
{
  int delta_x = abs (line.p1.x - line.p2.x);
  int delta_y = abs (line.p1.y - line.p2.y);

  return sqrt (delta_x * delta_x + delta_y * delta_y);
}

static double circumference (Triangle triangle)
{
  Line lines[3] = {
    {triangle.p1, triangle.p2}, {triangle.p2, triangle.p3}, {triangle.p3, triangle.p1}
  };

  return length (lines[0]) + length (lines[1]) + length (lines[2]);
}

static void printPoint (Point point)
{
  printf ("Point: (%d, %d)\n", point.x, point.y);
}

static void printLine (Line line)
{
  printf (
    "Line: (%d, %d) - (%d, %d) Length = %lf\n",
    line.p1.x, line.p1.y, line.p2.x, line.p2.y, length (line)
  );
}

static void printTriangle (Triangle triangle)
{
  printf (
    "Triangle: (%d, %d) - (%d, %d) - (%d, %d) Circumference: %lf\n",
    triangle.p1.x, triangle.p1.y,
    triangle.p2.x, triangle.p2.y,
    triangle.p3.x, triangle.p3.y,
    circumference (triangle)
  );
}
