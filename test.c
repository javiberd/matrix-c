#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
  Matrix *m1, *m2;
  init (&m1, 5, 2);
  init (&m2, 5, 2);
  set (m1, 0, 0, 5);
  set (m2, 4, 1, 2);
  add (m1, m2);
  printf ("%s\n", str (m1));
  printf ("----------------\n");
  printf ("%s\n", str (m2));
  sub (m1, m2);
  printf ("----------------\n");
  printf ("%s\n", str (m1));
  printf ("----------------\n");
  printf ("%s\n", str (m2));
  del (m1);
  del (m2);
  return 0;
}
