/**
  Author: Javier Berdecio Trigueros
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

Matrix *init (int nrow, int ncol, const int mat[nrow][ncol])
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

void set (Matrix *matrix, int i, int j, int value)
{
  matrix->mat[i][j] = value;
}

int get (const Matrix *matrix, int i, int j)
{
  return matrix->mat[i][j];
}

Matrix *add (Matrix *matrix_1, const Matrix *matrix_2)
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

Matrix *addn (const Matrix *matrix_1, const Matrix *matrix_2)
{
  int nrow = matrix_1->nrow, ncol = matrix_1->ncol;

  if (nrow != matrix_2->nrow || ncol != matrix_2->ncol) {
    return NULL;
  }

  int i, j;
  Matrix *res;
  res = init (nrow, ncol, NULL);
  for (i = 0; i < nrow; i++) {
    for (j = 0; j < ncol; j++) {
      res->mat[i][j] = matrix_1->mat[i][j] + matrix_2->mat[i][j];
    }
  }
  return res;
}

Matrix *sub (Matrix *matrix_1, const Matrix *matrix_2)
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

Matrix *subn (const Matrix *matrix_1, const Matrix *matrix_2)
{
  int nrow = matrix_1->nrow, ncol = matrix_1->ncol;

  if (nrow != matrix_2->nrow || ncol != matrix_2->ncol) {
    return NULL;
  }

  int i, j;
  Matrix *res;
  res = init (nrow, ncol, NULL);
  for (i = 0; i < nrow; i++) {
    for (j = 0; j < ncol; j++) {
      res->mat[i][j] = matrix_1->mat[i][j] - matrix_2->mat[i][j];
    }
  }
  return res;
}

Matrix *mul (Matrix *matrix_1, const Matrix *matrix_2)
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

Matrix *muln (const Matrix *matrix_1, const Matrix *matrix_2)
{
  int nrow = matrix_1->nrow, ncol = matrix_1->ncol;

  if (nrow != matrix_2->nrow || ncol != matrix_2->ncol) {
    return NULL;
  }

  int i, j;
  Matrix *res;
  res = init (nrow, ncol, NULL);
  for (i = 0; i < nrow; i++) {
    for (j = 0; j < ncol; j++) {
      res->mat[i][j] = matrix_1->mat[i][j] * matrix_2->mat[i][j];
    }
  }
  return res;
}

Matrix *mulp (const Matrix *matrix_1, const Matrix *matrix_2)
{
  int nrow1 = matrix_1->nrow, ncol1 = matrix_1->ncol, nrow2 = matrix_2->nrow,
    ncol2 = matrix_2->ncol;

  if (ncol1 != nrow2) {
    return NULL;
  }

  int i, j, k;
  Matrix *res;
  int **mat_1, **mat_2, **res_mat;
  res = init (nrow1, ncol2, NULL);
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

int equals (const Matrix *matrix_1, const Matrix *matrix_2)
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

char *str (const Matrix *matrix)
{
  int i, j;
  int nrow = matrix->nrow, ncol = matrix->ncol;
  char *out = (char *) malloc (sizeof (char) * nrow * ncol);
  char aux[10];
  for (i = 0; i < nrow; i++) {
    for (j = 0; j < ncol; j++) {
      sprintf (aux, "%i", matrix->mat[i][j]);
      strcat (out, aux);
    }
    strcat (out, "\n");
  }
  return out;
}

int get_nrow (const Matrix *matrix)
{
  return matrix->nrow;
}

int get_ncol (const Matrix *matrix)
{
  return matrix->ncol;
}

void del (Matrix *matrix)
{
  int i, nrow = matrix->nrow;
  for (i = 0; i < nrow; i++) {
    free (matrix->mat[i]);
  }
  free (matrix->mat);
  free (matrix);
}
