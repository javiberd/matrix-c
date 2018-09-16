/**
  Author: Javier Berdecio Trigueros
*/

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

typedef enum _Operations
{
  op_add,
  op_addc,
  op_sub,
  op_subc,
  op_mul
} Operations;

int main ()
{
  Matrix *m1, *m2, *res_add, *res_sub, *res_mul;
  int m1_t1_mat[5][4] = {
    {0, 1, 2, 3},
    {4, 5, 6, 7},
    {8, 9, 10, 11},
    {12, 13, 14, 15},
    {16, 17, 18, 19}
  };
  int m2_t1_mat[5][4] = {
    {19, 18, 17, 16},
    {15, 14, 13, 12},
    {11, 10, 9, 8},
    {7, 6, 5, 4},
    {3, 2, 1, 0}
  };
  int res_t1_add_mat[5][4] = {
    {19, 19, 19, 19},
    {19, 19, 19, 19},
    {19, 19, 19, 19},
    {19, 19, 19, 19},
    {19, 19, 19, 19}
  };
  int res_t1_sub_mat[5][4] = {
    {-19, -17, -15, -13},
    {-11, -9, -7, -5},
    {-3, -1, 1, 3},
    {5, 7, 9, 11},
    {13, 15, 17, 19}
  };

  // Initialization of matrices
  init (&m1, m1t1_mat, 5, 4);
  init (&m2, m2t1_mat, 5, 4);
  init (&res_add, res_t1_add_mat, 5, 4);

  // Test 1
  // Operation add
  if (test (op_add, m1, m2, res_add) == 1) {
    printf ("add test 1 passed\n", );
  }
  else {
    printf ("add test 1 failed\n", );
  }

  // Operation addc
  if (test (op_addc, m1, m2, res_add) == 1) {
    printf ("addc test 1 passed\n", );
  }
  else {
    printf ("addc test 1 failed\n", );
  }

  // Operation sub
  if (test (op_sub, m1, m2, res_sub) == 1) {
    printf ("sub test 1 passed\n", );
  }
  else {
    printf ("sub test 1 failed\n", );
  }

  // Operation subc
  if (test (op_subc, m1, m2, res_sub) == 1) {
    printf ("subc test 1 passed\n", );
  }
  else {
    printf ("subc test 1 failed\n", );
  }

  del (m1);
  del (m2);
  del (res_add);
  del (res_sub);

  return 0;
}

int test (Operations op, Matrix *m1, Matrix *m2, Matrix *res) {
  Matrix *m3;
  int free_m3 = 0;
  int ok = 0;

  // Operation
  switch (op) {
    case op_add:
      add (m1, m2);
      m3 = m1;
      break;
    case op_addc:
      m3 = addc (m1, m2);
      free_m3 = 1;
      break;
    case op_sub:
      sub (m1, m2);
      m3 = m1;
      break;
    case op_subc:
      m3 = subc (m1, m2);
      free_m3 = 1;
      break;
    case op_mul:
      m3 = mul (m1, m2);
      free_m3 =1;
      break;
  }


  // Check result
  if (equals(res, m3)) {
    ok = 1;
  }

  // Free memory from result if necessary
  if (free_m3 == 1) {
    free(m3);
  }

  return ok;
}
