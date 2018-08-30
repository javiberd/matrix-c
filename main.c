/**
  Author: Javier Berdecio Trigueros
*/

#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
  Matrix *m1, *m2, *m3;
  init (&m1, 3, 3);
  init (&m2, 3, 3);
  set (m1, 0, 0, 5);
  set (m1, 0, 1, 4);
  set (m2, 2, 1, 2);
  set (m2, 1, 1, 4);
  add (m1, m2);
  printf ("%s\n", str (m1));
  printf ("----------------\n");
  printf ("%s\n", str (m2));
  sub (m1, m2);
  printf ("----------------\n");
  printf ("%s\n", str (m1));
  printf ("----------------\n");
  printf ("%s\n", str (m2));
  m3 = mul (m1, m2);
  printf ("----------------\n");
  printf ("%s\n", str (m3));
  printf ("----------------\n");
  del (m1);
  del (m2);
  del (m3);
  return 0;
}
