/**
  Author: Javier Berdecio Trigueros
*/

#ifndef MATRIX_H_
#define MATRIX_H_

typedef struct _Matrix Matrix;

/**
  Initiliazes a rows * cols matrix, mat is copied into the new matrix. If mat
  is NULL then new matrix will be filled with 0's
*/
Matrix *init  (int           rows,
               int           cols,
               const int     mat[rows][cols]);

/**
  Sets value of position (i, j) of the matrix to the parameter 'value'
*/
void    set    (Matrix       *matrix,
                int           i,
                int           j,
                int           value);

/**
  Returns value of position (i, j) of the matrix
*/
int     get    (const Matrix *matrix,
                int           i,
                int           j);
/**
  Adds matrix_2 to matrix_1, result is saved in matrix_1
*/
Matrix *add    (Matrix       *matrix_1,
                const Matrix *matrix_2);

/**
  Adds matrix_2 to matrix_1, result is returned
*/
Matrix *addr   (const Matrix *matrix_1,
                const Matrix *matrix_2);

/**
  Subtracts matrix_2 to matrix_1, result is saved in matrix_1
*/
Matrix *sub    (Matrix       *matrix_1,
                const Matrix *matrix_2);

/**
  Subtracts matrix_2 to matrix_1, result is returned
*/
Matrix *subr   (const Matrix *matrix_1,
                const Matrix *matrix_2);

/**
  Multiplies matrix_1 and matrix_2 with the naive method and then returns
  that matrix
*/
Matrix *mul    (const Matrix *matrix_1,
                const Matrix *matrix_2);

/**
  Compares two matrices, 1 is returned if both represent the same matrix. 0, if
  both represent different matrices
*/
int     equals (const Matrix *matrix_1,
                const Matrix *matrix_2);

/**
  Returns a string with the graphical representation of the matrix
*/
char   *str    (const Matrix *matrix);

/**
  Frees all memory allocated
*/
void    del    (Matrix       *matrix);

#endif
