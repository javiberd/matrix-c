/**
  @file matrix.h

  File containing all functions applicable to Matrix objects.

  In OOP these are called the methods of the class.

  @author Javier Berdecio Trigueros
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
Matrix *Matrix_init     (int           nrow,
                         int           ncol,
                         const int     mat[nrow][ncol]);

/**
  Sets the value of the position (i, j) of the matrix to the value passed as
  argument.
  @param matrix Matrix to be modified.
  @param i      Row of the matrix.
  @param j      Column of the matrix.
  @param value  Value to be set.
*/
void    Matrix_set      (Matrix       *matrix,
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
int     Matrix_get      (const Matrix *matrix,
                         int           i,
                         int           j);
/**
  Adds matrix_2 to matrix_1, result is saved in matrix_1.
  @param matrix_1 One of the matrices to operate with. This will contain the
  resulting matrix.
  @param matrix_2 One of the matrices to operate with.
  @return The resulting matrix (matrix_1) or NULL if the matrices differ on
  number of colums or rows.
*/
Matrix *Matrix_add      (Matrix       *matrix_1,
                         const Matrix *matrix_2);

/**
  Adds matrix_2 to matrix_1, result is returned in a newly allocated matrix.
  The two characters suffix of this function's name is "rn". This is to
  emphasize in that the function 'r'eturns a 'n'ewly allocated matrix.
  @param matrix_1 One of the matrices to operate with.
  @param matrix_2 One of the matrices to operate with.
  @return The resulting matrix or NULL if the matrices differ on number of
  colums or rows.
*/
Matrix *Matrix_addrn    (const Matrix *matrix_1,
                         const Matrix *matrix_2);

/**
  Subtracts matrix_2 to matrix_1, result is saved in matrix_1.
  @param matrix_1 One of the matrices to operate with. This will contain the
  resulting matrix.
  @param matrix_2 One of the matrices to operate with.
  @return The resulting matrix (matrix_1) or NULL if the matrices differ on
  number of colums or rows.
*/
Matrix *Matrix_sub      (Matrix       *matrix_1,
                         const Matrix *matrix_2);

/**
  Subtracts matrix_2 to matrix_1, result is returned in a newly allocated
  matrix. The two characters suffix of this function's name is "rn". This is to
  emphasize in that the function 'r'eturns a 'n'ewly allocated matrix.
  @param matrix_1 One of the matrices to operate with.
  @param matrix_2 One of the matrices to operate with.
  @return The resulting matrix or NULL if the matrices differ on
  number of colums or rows.
*/
Matrix *Matrix_subrn    (const Matrix *matrix_1,
                         const Matrix *matrix_2);

/**
  Multiplies matrix_1 and matrix_2 element by element and then returns
  that matrix. This operation is known as Hadamard product of matrices.
  @param matrix_1 One of the matrices to operate with.
  @param matrix_2 One of the matrices to operate with.
  @return The resulting matrix or NULL if the matrices differ on
  number of colums or rows.
*/
Matrix *Matrix_mul      (Matrix       *matrix_1,
                         const Matrix *matrix_2);

/**
  Multiplies matrix_1 and matrix_2 element by element, result is returned in
  a newly allocated matrix. This operation is known as Hadamard product of
  matrices.The two characters suffix of this function's name is "rn". This is
  to emphasize in that the function 'r'eturns a 'n'ewly allocated matrix.
  @param matrix_1 One of the matrices to operate with.
  @param matrix_2 One of the matrices to operate with.
  @return The resulting matrix or NULL if the matrices differ on
  number of colums or rows.
*/
Matrix *Matrix_mulrn    (const Matrix *matrix_1,
                         const Matrix *matrix_2);

/**
  Multiplies matrix_1 and matrix_2 with the naive method and then returns
  that matrix. The one character suffix of this function's name is "n". This
  is to emphasize in that the 'n'aive method is of multiplication is used.
  @param matrix_1 One of the matrices to operate with.
  @param matrix_2 One of the matrices to operate with.
  @return The resulting matrix or NULL if the number of columns of matrix_1
  differs of the number of rows of matrix_2.
*/
Matrix *Matrix_muln     (const Matrix *matrix_1,
                         const Matrix *matrix_2);

/**
  Compares two matrices, 1 is returned if both represent the same matrix. If
  both represent different matrices, then 0 is returned.
  @param matrix_1 One of the matrices to compare with.
  @param matrix_2 One of the matrices to compare with.
  @return The result of the comparison.
*/
int     Matrix_equals   (const Matrix *matrix_1,
                         const Matrix *matrix_2);

/**
  Returns a string that represents the matrix.
  @param matrix Matrix to be represented as a string.
  @return The representation of the matrix as a string.
*/
char   *Matrix_str      (const Matrix *matrix);

/**
  Returns the number of rows that the matrix have.
  @param matrix A matrix.
  @return Number of rows.
*/
int     Matrix_get_nrow (const Matrix *matrix);

/**
  Returns the number of columns that the matrix have.
  @param matrix A matrix.
  @return Number of columns.
*/
int     Matrix_get_ncol (const Matrix *matrix);

/**
  Frees all memory allocated.
  @param Matrix to be freed.
*/
void    Matrix_del      (Matrix       *matrix);

#endif
