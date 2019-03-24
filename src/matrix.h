/**
  @file matrix.h

  This is something

  Author: Javier Berdecio Trigueros
*/

#ifndef MATRIX_H_
#define MATRIX_H_

typedef struct _Matrix Matrix;

/**
  Initiliazes a rows * cols matrix, mat is copied into the new matrix. If mat
  is NULL then new matrix will be filled with 0's.

  @param nrow   Number of rows that the new matrix will have.
  @param ncol   Number of columns that the new matrix will have.
  @param mat    Matrix with the values to be copied into the new matrix. If
                NULL, matrix will be filled with 0's.
  @return       A new matrix, or NULL if it was not possible to allocate memory.
*/
Matrix *init  (int           nrow,
               int           ncol,
               const int     mat[nrow][ncol]);

/**
  Sets the value of the position (i, j) of the matrix to the value of parameter
  \value.
  @param matrix Matrix to be modified.
  @param i      Row of the matrix.
  @param j      Column of the matrix.
  @param value  Value to be set.
*/
void    set      (Matrix       *matrix,
                  int           i,
                  int           j,
                  int           value);

/**
  Gets the value in the position (i, j) of the matrix.
  @param matrix Matrix where is intended to get the value from.
  @param i      Row of the matrix.
  @param j      Column of the matrix.
  @return       The value in position (i, j) of the matrix.
*/
int     get      (const Matrix *matrix,
                  int           i,
                  int           j);
/**
  Adds matrix_2 to matrix_1, result is saved in matrix_1.
  @param matrix_1 One of the matrices to operate with. This will contain the
                  resulting matrix.
  @param matrix_2 One of the matrices to operate with.
  @return The resulting matrix (matrix_1).
*/
Matrix *add      (Matrix       *matrix_1,
                  const Matrix *matrix_2);

/**
  Adds matrix_2 to matrix_1, result is returned in a newly allocated matrix.
  @param matrix_1 One of the matrices to operate with.
  @param matrix_2 One of the matrices to operate with.
  @return The resulting matrix.
*/
Matrix *addn     (const Matrix *matrix_1,
                  const Matrix *matrix_2);

/**
  Subtracts matrix_2 to matrix_1, result is saved in matrix_1.
  @param matrix_1 One of the matrices to operate with. This will contain the
                  resulting matrix.
  @param matrix_2 One of the matrices to operate with.
  @return The resulting matrix (matrix_1).
*/
Matrix *sub      (Matrix       *matrix_1,
                  const Matrix *matrix_2);

/**
  Subtracts matrix_2 to matrix_1, result is returned in a newly allocated
  matrix.
  @param matrix_1 One of the matrices to operate with.
  @param matrix_2 One of the matrices to operate with.
  @return The resulting matrix.
*/
Matrix *subn     (const Matrix *matrix_1,
                  const Matrix *matrix_2);

/**
  Multiplies matrix_1 and matrix_2 element by element and then returns
  that matrix.
  @param matrix_1 One of the matrices to operate with.
  @param matrix_2 One of the matrices to operate with.
  @return The resulting matrix.
*/
Matrix *mul      (Matrix *matrix_1,
                  const Matrix *matrix_2);

/**
  Multiplies matrix_1 and matrix_2 element by element, result is returned in
  a newly allocated matrix.
  @param matrix_1 One of the matrices to operate with.
  @param matrix_2 One of the matrices to operate with.
  @return The resulting matrix.
*/
Matrix *muln     (const Matrix *matrix_1,
                  const Matrix *matrix_2);

/**
  Multiplies matrix_1 and matrix_2 with the naive method and then returns
  that matrix.
  @param matrix_1 One of the matrices to operate with.
  @param matrix_2 One of the matrices to operate with.
  @return The resulting matrix.
*/
Matrix *mulp     (const Matrix *matrix_1,
                  const Matrix *matrix_2);

/**
  Compares two matrices, 1 is returned if both represent the same matrix. If
  both represent different matrices, then 0 is returned.
  @param matrix_1 One of the matrices to compare with.
  @param matrix_2 One of the matrices to compare with.
  @return The result of the comparison.
*/
int     equals   (const Matrix *matrix_1,
                  const Matrix *matrix_2);

/**
  Returns a string that represents the matrix.
  @param matrix Matrix to be represented as a string.
  @return The representation of the matrix as a string.
*/
char   *str      (const Matrix *matrix);

/**
  Returns the number of rows that the matrix have.
  @param matrix A matrix.
  @return Number of rows.
*/
int     get_nrow (const Matrix *matrix);

/**
  Returns the number of columns that the matrix have.
  @param matrix A matrix.
  @return Number of columns.
*/
int     get_ncol (const Matrix *matrix);

/**
  Frees all memory allocated.
  @param Matrix to be freed.
*/
void    del    (Matrix       *matrix);

#endif
