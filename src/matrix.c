/**
  Implementation of functions declared in matrix.h.

  @author Javier Berdecio Trigueros
*/

#include "matrix.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct _Matrix
{
  int nrow;
  int ncol;
  int** mat;
};

Matrix *Matrix_init (int nrow, int ncol, const int mat[nrow][ncol])
{
  Matrix *matrix = (Matrix *) malloc (sizeof (Matrix));
  if (matrix == NULL) {
    return NULL;
  }
  matrix->nrow = nrow;
  matrix->ncol = ncol;
  matrix->mat = (int**) malloc (sizeof (int *) * nrow);
  for (int i = 0; i < nrow; i++) {
    matrix->mat[i] = (int*) malloc (sizeof (int) * ncol);
    for (int j = 0; j < ncol; j++) {
      if (mat != NULL) {
        matrix->mat[i][j] = mat[i][j];
      }
      else {
        matrix->mat[i][j] = 0;
      }
    }
  }
  return matrix;
}

void Matrix_set (Matrix *matrix, int i, int j, int value)
{
  if (i >= 0 && i < matrix->nrow && j >= 0 && j < matrix->ncol) {

  }
  matrix->mat[i][j] = value;
}

int Matrix_get (const Matrix *matrix, int i, int j)
{
  if (i >= 0 && i < matrix->nrow && j >= 0 && j < matrix->ncol) {

  }
  return matrix->mat[i][j];
}

Matrix *Matrix_add (Matrix *matrix_1, const Matrix *matrix_2)
{
  int nrow = matrix_1->nrow, ncol = matrix_1->ncol;

  if (nrow != matrix_2->nrow || ncol != matrix_2->ncol) {
    return NULL;
  }

  int i, j;
  for (i = 0; i < nrow; i++) {
    for (j = 0; j < ncol; j++) {
      matrix_1->mat[i][j] = matrix_1->mat[i][j] + matrix_2->mat[i][j];
    }
  }
  return matrix_1;
}

Matrix *Matrix_addrn (const Matrix *matrix_1, const Matrix *matrix_2)
{
  int nrow = matrix_1->nrow, ncol = matrix_1->ncol;

  if (nrow != matrix_2->nrow || ncol != matrix_2->ncol) {
    return NULL;
  }

  int i, j;
  Matrix *res;
  res = Matrix_init (nrow, ncol, NULL);
  for (i = 0; i < nrow; i++) {
    for (j = 0; j < ncol; j++) {
      res->mat[i][j] = matrix_1->mat[i][j] + matrix_2->mat[i][j];
    }
  }
  return res;
}

Matrix *Matrix_sub (Matrix *matrix_1, const Matrix *matrix_2)
{
  int nrow = matrix_1->nrow, ncol = matrix_1->ncol;

  if (nrow != matrix_2->nrow || ncol != matrix_2->ncol) {
    return NULL;
  }

  int i, j;
  for (i = 0; i < nrow; i++) {
    for (j = 0; j < ncol; j++) {
      matrix_1->mat[i][j] = matrix_1->mat[i][j] - matrix_2->mat[i][j];
    }
  }
  return matrix_1;
}

Matrix *Matrix_subrn (const Matrix *matrix_1, const Matrix *matrix_2)
{
  int nrow = matrix_1->nrow, ncol = matrix_1->ncol;

  if (nrow != matrix_2->nrow || ncol != matrix_2->ncol) {
    return NULL;
  }

  int i, j;
  Matrix *res;
  res = Matrix_init (nrow, ncol, NULL);
  for (i = 0; i < nrow; i++) {
    for (j = 0; j < ncol; j++) {
      res->mat[i][j] = matrix_1->mat[i][j] - matrix_2->mat[i][j];
    }
  }
  return res;
}

Matrix *Matrix_mul (Matrix *matrix_1, const Matrix *matrix_2)
{
  int nrow = matrix_1->nrow, ncol = matrix_1->ncol;

  if (nrow != matrix_2->nrow || ncol != matrix_2->ncol) {
    return NULL;
  }

  int i, j;
  for (i = 0; i < nrow; i++) {
    for (j = 0; j < ncol; j++) {
      matrix_1->mat[i][j] = matrix_1->mat[i][j] * matrix_2->mat[i][j];
    }
  }
  return matrix_1;
}

Matrix *Matrix_mulrn (const Matrix *matrix_1, const Matrix *matrix_2)
{
  int nrow = matrix_1->nrow, ncol = matrix_1->ncol;

  if (nrow != matrix_2->nrow || ncol != matrix_2->ncol) {
    return NULL;
  }

  int i, j;
  Matrix *res;
  res = Matrix_init (nrow, ncol, NULL);
  for (i = 0; i < nrow; i++) {
    for (j = 0; j < ncol; j++) {
      res->mat[i][j] = matrix_1->mat[i][j] * matrix_2->mat[i][j];
    }
  }
  return res;
}

Matrix *Matrix_muln (const Matrix *matrix_1, const Matrix *matrix_2)
{
  int nrow1 = matrix_1->nrow, ncol1 = matrix_1->ncol, nrow2 = matrix_2->nrow,
    ncol2 = matrix_2->ncol;

  if (ncol1 != nrow2) {
    return NULL;
  }

  int i, j, k;
  Matrix *res;
  int **mat_1, **mat_2, **res_mat;
  res = Matrix_init (nrow1, ncol2, NULL);
  mat_1 = matrix_1->mat;
  mat_2 = matrix_2->mat;
  res_mat = res->mat;
  for (i = 0; i < nrow1; i++) {
    for (j = 0; j < ncol2; j++) {
        res_mat[i][j] = 0;
      for (k = 0; k < ncol1; k++) {
        res_mat[i][j] += mat_1[i][k] * mat_2[k][j];
      }
    }
  }
  return res;
}

int Matrix_equals (const Matrix *matrix_1, const Matrix *matrix_2)
{
  int i, j;
  int nrow = matrix_1->nrow, ncol = matrix_1->ncol;
  for (i = 0; i < nrow; i++) {
    for (j = 0; j < ncol; j++) {
      if (matrix_1->mat[i][j] != matrix_2->mat[i][j]) {
        return 0;
      }
    }
  }
  return 1;
}

char *Matrix_str (const Matrix *matrix)
{
  int i, j;
  int nrow = matrix->nrow, ncol = matrix->ncol;
  // Note that 11 is the largest int length (in characters) plus sign
  char *out = (char *) malloc (sizeof (char) * nrow * ncol * 11);
  char aux[11];
  for (i = 0; i < nrow; i++) {
    for (j = 0; j < ncol; j++) {
      if (j < ncol - 1) {
        // Write element with an appended space
        sprintf (aux, "%i ", matrix->mat[i][j]);
      }
      else {
        // Last element of the row does not write an extra space
        sprintf (aux, "%i", matrix->mat[i][j]);
      }
      strcat (out, aux);
    }
    strcat (out, "\n");
  }
  return out;
}

int Matrix_get_nrow (const Matrix *matrix)
{
  return matrix->nrow;
}

int Matrix_get_ncol (const Matrix *matrix)
{
  return matrix->ncol;
}

void Matrix_del (Matrix *matrix)
{
  int i, nrow = matrix->nrow;
  for (i = 0; i < nrow; i++) {
    free (matrix->mat[i]);
  }
  free (matrix->mat);
  free (matrix);
}
