#include "matrix.h"

#include <stdlib.h>
#include <stdio.h>

struct _Matrix
{
  int size;
  int** mat;
};

void init(Matrix **matrix, int size)
{
  (*matrix) = (Matrix *) malloc(sizeof(Matrix));
  (*matrix)->size = size;
  (*matrix)->mat = (int**) malloc(sizeof(int *) * size);
  for (int i = 0; i < size; i++) {
    (*matrix)->mat[i] = (int*) malloc(sizeof(int) * size);
  }
}

void set(Matrix *matrix, int i, int j, int value)
{
  matrix->mat[i][j] = value;
}

int get(Matrix *matrix, int i, int j)
{
  return matrix->mat[i][j];
}

void add(Matrix *matrix_1, Matrix *matrix_2)
{
  int i, j, size = matrix_1->size;
  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      matrix_1->mat[i][j] = matrix_1->mat[i][j] + matrix_2->mat[i][j];
    }
  }
}

void sub(Matrix *matrix_1, Matrix *matrix_2)
{
  int i, j, size = matrix_1->size;
  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      matrix_1->mat[i][j] = matrix_1->mat[i][j] - matrix_2->mat[i][j];
    }
  }
}

void print(Matrix *matrix)
{
  int i, j, size = matrix->size;
  for (i = 0; i < size; i++) {
    for (j = 0; j < size; j++) {
      printf("%i ", matrix->mat[i][j]);
    }
    printf("\n");
  }
}

void del(Matrix *matrix)
{
  int i, size = matrix->size;
  for (i = 0; i < size; i++) {
    free(matrix->mat[i]);
  }
  free(matrix->mat);
  free(matrix);
}
