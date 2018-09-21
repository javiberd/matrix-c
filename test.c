/**
  Author: Javier Berdecio Trigueros
*/

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

typedef enum
{
  OP_ADD,
  OP_ADDR,
  OP_SUB,
  OP_SUBR,
  OP_MUL
} Operation;

int test (Operation OP, Matrix *m1, Matrix *m2, Matrix *res) {
  Matrix *m3;
  int free_m3 = 0;
  int ok = 0;

  // Operation
  switch (OP) {
    case OP_ADD:
      add (m1, m2);
      m3 = m1;
      break;
    case OP_ADDR:
      m3 = addr (m1, m2);
      free_m3 = 1;
      break;
    case OP_SUB:
      sub (m1, m2);
      m3 = m1;
      break;
    case OP_SUBR:
      m3 = subr (m1, m2);
      free_m3 = 1;
      break;
    case OP_MUL:
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
  int t1_mul_mat1[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 0}
  };
  int t1_mul_mat2[4][2] = {
    {12, 11},
    {9, 8},
    {6, 5},
    {3, 2}
  };
  int t1_mul_res_mat[3][2] = {
    {60, 50},
    {180, 154},
    {264, 234}
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


  // Initialization of matrices that contain expected results
  init (&res_add, 5, 4, res_t1_add_mat);
  init (&res_sub, 5, 4, res_t1_sub_mat);
  init (&res_mul, 3, 2, t1_mul_res_mat);

  // Test 1
  // Operation add
  // Initialization of matrices
  init (&m1, 5, 4, m1_t1_mat);
  init (&m2, 5, 4, m2_t1_mat);
  // Execution of operation
  if (test (OP_ADD, m1, m2, res_add) == 1) {
    printf ("add test 1 passed\n");
  }
  else {
    printf ("add test 1 failed\n");
  }

  // Operation addc
  // Initialization of matrices
  init (&m1, 5, 4, m1_t1_mat);
  init (&m2, 5, 4, m2_t1_mat);
  // Execution of operation
  if (test (OP_ADDR, m1, m2, res_add) == 1) {
    printf ("addr test 1 passed\n");
  }
  else {
    printf ("addr test 1 failed\n");
  }

  // Operation sub
  // Initialization of matrices
  init (&m1, 5, 4, m1_t1_mat);
  init (&m2, 5, 4, m2_t1_mat);
  // Execution of operation
  if (test (OP_SUB, m1, m2, res_sub) == 1) {
    printf ("sub test 1 passed\n");
  }
  else {
    printf ("sub test 1 failed\n");
  }

  // Operation subc
  // Initialization of matrices
  init (&m1, 5, 4, m1_t1_mat);
  init (&m2, 5, 4, m2_t1_mat);
  // Execution of operation
  if (test (OP_SUBR, m1, m2, res_sub) == 1) {
    printf ("subr test 1 passed\n");
  }
  else {
    printf ("subr test 1 failed\n");
  }

  // Operation mul
  // Initialization of matrices
  init (&m1, 3, 4, t1_mul_mat1);
  init (&m2, 4, 2, t1_mul_mat2);
  // Execution of operation
  if (test (OP_MUL, m1, m2, res_mul) == 1) {
    printf ("mul test 1 passed\n");
  }
  else {
    printf ("mul test 1 failed\n");
  }

  del (m1);
  del (m2);
  del (res_add);
  del (res_sub);
  del (res_mul);

  return 0;
}
