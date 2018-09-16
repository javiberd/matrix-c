/**
  Author: Javier Berdecio Trigueros
*/

#include "matrix.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct _Matrix
{
  int rows;
  int cols;
  int** mat;
};

void init (Matrix **matrix, int rows, int cols)
{
  (*matrix) = (Matrix *) malloc (sizeof (Matrix));
  (*matrix)->rows = rows;
  (*matrix)->cols = cols;
  (*matrix)->mat = (int**) malloc (sizeof (int *) * rows);
  for (int i = 0; i < rows; i++) {
    (*matrix)->mat[i] = (int*) malloc (sizeof (int) * cols);
  }
}

void init (Matrix **matrix, int **mat, int rows, int cols)
{
  (*matrix) = (Matrix *) malloc (sizeof (Matrix));
  (*matrix)->rows = rows;
  (*matrix)->cols = cols;
  (*matrix)->mat = (int**) malloc (sizeof (int *) * rows);
  for (int i = 0; i < rows; i++) {
    (*matrix)->mat[i] = (int*) malloc (sizeof (int) * cols);
    for (int j = 0; j < cols; j++) {
      (*matrix)->mat[i][j] = mat[i][j];
    }
  }
}

void set (Matrix *matrix, int i, int j, int value)
{
  matrix->mat[i][j] = value;
}

int get (Matrix *matrix, int i, int j)
{
  return matrix->mat[i][j];
}

void add (Matrix *matrix_1, Matrix *matrix_2)
{
  int i, j;
  int rows = matrix_1->rows, cols = matrix_1->cols;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      matrix_1->mat[i][j] = matrix_1->mat[i][j] + matrix_2->mat[i][j];
    }
  }
}

Matrix *addc (Matrix *matrix_1, Matrix *matrix_2)
{
  int i, j;
  int rows = matrix_1->rows, cols = matrix_1->cols;
  Matrix *res;
  init(res, rows, cols);
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      res->mat[i][j] = matrix_1->mat[i][j] + matrix_2->mat[i][j];
    }
  }
  return res;
}

void sub (Matrix *matrix_1, Matrix *matrix_2)
{
  int i, j;
  int rows = matrix_1->rows, cols = matrix_1->cols;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      matrix_1->mat[i][j] = matrix_1->mat[i][j] - matrix_2->mat[i][j];
    }
  }
}

Matrix *subc (Matrix *matrix_1, Matrix *matrix_2)
{
  int i, j;
  int rows = matrix_1->rows, cols = matrix_1->cols;
  Matrix *res;
  init(res, rows, cols);
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      res->mat[i][j] = matrix_1->mat[i][j] - matrix_2->mat[i][j];
    }
  }
  return res;
}

Matrix *mul (Matrix *matrix_1, Matrix *matrix_2)
{
  int i, j, k;
  int rows1 = matrix_1->rows, cols1 = matrix_1->cols, cols2 = matrix_2->cols;
  Matrix *res;
  int **mat_1, **mat_2, **res_mat;
  init (&res, rows1, cols2);
  mat_1 = matrix_1->mat;
  mat_2 = matrix_2->mat;
  res_mat = res->mat;
  for (i = 0; i < rows1; i++) {
    for (j = 0; j < cols2; j++) {
        res_mat[i][j] = 0;
      for (k = 0; k < cols1; k++) {
        res_mat[i][j] += mat_1[i][k] * mat_2[k][j];
      }
    }
  }
  return res;
}

int equals (Matrix *matrix_1, Matrix *matrix_2)
{
  int i, j;
  int rows = matrix_1->rows, cols = matrix_1->cols;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      if (matrix_1->mat[i][j] != matrix_2->mat[i][j]) {
        return 0;
      }
    }
  }
  return 1;
}

char *str (Matrix *matrix)
{
  int i, j;
  int rows = matrix->rows, cols = matrix->cols;
  char *out = (char *) malloc (sizeof (char) * rows * cols);
  char aux[10];
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      sprintf (aux, "%i", matrix->mat[i][j]);
      strcat (out, aux);
    }
    strcat (out, "\n");
  }
  return out;
}

void del (Matrix *matrix)
{
  int i, rows = matrix->rows;
  for (i = 0; i < rows; i++) {
    free (matrix->mat[i]);
  }
  free (matrix->mat);
  free (matrix);
}
