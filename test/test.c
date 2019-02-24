/**
  Author: Javier Berdecio Trigueros
*/

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

typedef enum
{
  OP_ADD,
  OP_ADDN,
  OP_SUB,
  OP_SUBN,
  OP_MUL,
  OP_MULN,
  OP_MULP,
} Operation;

int test (Operation OP, Matrix *m1, Matrix *m2, Matrix *res) {
  Matrix *m3;
  int free_m3 = 0;
  int ok = 0;

  // Operation
  switch (OP) {
    case OP_ADD:
      m3 = add (m1, m2);
      break;
    case OP_ADDN:
      m3 = addn (m1, m2);
      free_m3 = 1;
      break;
    case OP_SUB:
      m3 = sub (m1, m2);
      break;
    case OP_SUBN:
      m3 = subn (m1, m2);
      free_m3 = 1;
      break;
    case OP_MUL:
      m3 = mul (m1, m2);
      break;
    case OP_MULN:
      m3 = muln (m1, m2);
      break;
    case OP_MULP:
      m3 = mulp (m1, m2);
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

void test_add () {
  int t1_add_mat1[5][4] = {
    {0, 1, 2, 3},
    {4, 5, 6, 7},
    {8, 9, 10, 11},
    {12, 13, 14, 15},
    {16, 17, 18, 19}
  };
  int t1_add_mat2[5][4] = {
    {19, 18, 17, 16},
    {15, 14, 13, 12},
    {11, 10, 9, 8},
    {7, 6, 5, 4},
    {3, 2, 1, 0}
  };
  int t1_add_res_mat[5][4] = {
    {19, 19, 19, 19},
    {19, 19, 19, 19},
    {19, 19, 19, 19},
    {19, 19, 19, 19},
    {19, 19, 19, 19}
  };
  Matrix *m1, *m2, *res;

  // Initialization of matrices
  m1 = init (5, 4, t1_add_mat1);
  m2 = init (5, 4, t1_add_mat2);
  res = init (5, 4, t1_add_res_mat);

  // Execution of operation addn
  if (test (OP_ADDN, m1, m2, res) == 1) {
    printf ("addn test 1: passed\n");
  }
  else {
    printf ("addn test 1: failed\n");
  }

  // Execution of operation add
  if (test (OP_ADD, m1, m2, res) == 1) {
    printf ("add test 1: passed\n");
  }
  else {
    printf ("add test 1: failed\n");
  }

  del (m1);
  del (m2);
  del (res);
}

void test_sub () {
  int t1_sub_mat1[5][4] = {
    {0, 1, 2, 3},
    {4, 5, 6, 7},
    {8, 9, 10, 11},
    {12, 13, 14, 15},
    {16, 17, 18, 19}
  };
  int t1_sub_mat2[5][4] = {
    {19, 18, 17, 16},
    {15, 14, 13, 12},
    {11, 10, 9, 8},
    {7, 6, 5, 4},
    {3, 2, 1, 0}
  };
  int t1_sub_res_mat[5][4] = {
    {-19, -17, -15, -13},
    {-11, -9, -7, -5},
    {-3, -1, 1, 3},
    {5, 7, 9, 11},
    {13, 15, 17, 19}
  };
  Matrix *m1, *m2, *res;

  // Initialization of matrices
  m1 = init (5, 4, t1_sub_mat1);
  m2 = init (5, 4, t1_sub_mat2);
  res = init (5, 4, t1_sub_res_mat);

  // Execution of operation subn
  if (test (OP_SUBN, m1, m2, res) == 1) {
    printf ("subn test 1: passed\n");
  }
  else {
    printf ("subn test 1: failed\n");
  }

  // Execution of operation sub
  if (test (OP_SUB, m1, m2, res) == 1) {
    printf ("sub test 1: passed\n");
  }
  else {
    printf ("sub test 1: failed\n");
  }

  del (m1);
  del (m2);
  del (res);
}

void test_mul () {
  int t1_mul_mat1[5][4] = {
    {0, 1, 2, 3},
    {4, 5, 6, 7},
    {8, 9, 10, 11},
    {12, 13, 14, 15},
    {16, 17, 18, 19}
  };
  int t1_mul_mat2[5][4] = {
    {19, 18, 17, 16},
    {15, 14, 13, 12},
    {11, 10, 9, 8},
    {7, 6, 5, 4},
    {3, 2, 1, 0}
  };
  int t1_mul_res_mat[5][4] = {
    {0, 18, 34, 48},
    {60, 70, 78, 84},
    {88, 90, 90, 88},
    {84, 78, 70, 60},
    {48, 34, 18, 0}
  };
  Matrix *m1, *m2, *res;

  // Initialization of matrices
  m1 = init (5, 4, t1_mul_mat1);
  m2 = init (5, 4, t1_mul_mat2);
  res = init (5, 4, t1_mul_res_mat);

  // Execution of operation muln
  if (test (OP_MULN, m1, m2, res) == 1) {
    printf ("muln test 1: passed\n");
  }
  else {
    printf ("muln test 1: failed\n");
  }

  // Execution of operation mul
  if (test (OP_MUL, m1, m2, res) == 1) {
    printf ("mul test 1: passed\n");
  }
  else {
    printf ("mul test 1: failed\n");
  }

  del (m1);
  del (m2);
  del (res);
}

void test_mulp () {
  int t1_mulp_mat1[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 0}
  };
  int t1_mulp_mat2[4][2] = {
    {12, 11},
    {9, 8},
    {6, 5},
    {3, 2}
  };
  int t1_mulp_res_mat[3][2] = {
    {60, 50},
    {180, 154},
    {264, 234}
  };
  Matrix *m1, *m2, *res;

  // Initialization of matrices
  m1 = init (3, 4, t1_mulp_mat1);
  m2 = init (4, 2, t1_mulp_mat2);
  res = init (3, 2, t1_mulp_res_mat);

  // Execution of operation
  if (test (OP_MULP, m1, m2, res) == 1) {
    printf ("mulp test 1: passed\n");
  }
  else {
    printf ("mulp test 1: failed\n");
  }

  del (m1);
  del (m2);
  del (res);
}

int main ()
{
  test_add ();
  test_sub ();
  test_mul ();
  test_mulp ();
  return 0;
}
