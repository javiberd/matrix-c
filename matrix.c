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
  (*matrix) = (Matrix *) malloc (sizeof(Matrix));
  (*matrix)->rows = rows;
  (*matrix)->cols = cols;
  (*matrix)->mat = (int**) malloc (sizeof(int *) * rows);
  for (int i = 0; i < rows; i++) {
    (*matrix)->mat[i] = (int*) malloc (sizeof(int) * cols);
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

void sub(Matrix *matrix_1, Matrix *matrix_2)
{
  int i, j;
  int rows = matrix_1->rows, cols = matrix_1->cols;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      matrix_1->mat[i][j] = matrix_1->mat[i][j] - matrix_2->mat[i][j];
    }
  }
}

Matrix *mul (Matrix *matrix_1, Matrix *matrix_2)
{
  Matrix *res = NULL;
  return res;
}

char *str(Matrix *matrix)
{
  int i, j;
  int rows = matrix->rows, cols = matrix->cols;
  char *out = (char *) malloc(sizeof(char) * rows * cols);
  char aux[10];
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      sprintf(aux, "%i", matrix->mat[i][j]);
      strcat(out, aux);
    }
    strcat(out, "\n");
  }
  return out;
}

void del(Matrix *matrix)
{
  int i, size = matrix->cols;
  for (i = 0; i < size; i++) {
    free (matrix->mat[i]);
  }
  free (matrix->mat);
  free (matrix);
}
