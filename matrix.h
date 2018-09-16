/**
  Author: Javier Berdecio Trigueros
*/

#ifndef MATRIX_H_
#define MATRIX_H_

typedef struct _Matrix Matrix;

/**
  Initiliazes a rows * cols matrix
*/
void    init   (Matrix **matrix,
                int      rows,
                int      cols);
/**
  Initiliazes a rows * cols matrix, mat is copied into the new matrix
*/
void    init  (Matrix **matrix,
                int    **mat,
                int      rows,
                int      cols);

/**
  Sets value of position (i, j) of the matrix to the parameter 'value'
*/
void    set    (Matrix *matrix,
                int     i,
                int     j,
                int     value);

/**
  Returns value of position (i, j) of the matrix
*/
int     get    (Matrix *matrix,
                int     i,
                int     j);
/**
  Adds matrix_2 to matrix_1, result is saved in matrix_1
*/
void    add    (Matrix *matrix_1,
                Matrix *matrix_2)

/**
  Adds matrix_2 to matrix_1, result is returned
*/
Matrix *addc   (Matrix *matrix_1,
                Matrix *matrix_2);

/**
  Subtracts matrix_2 to matrix_1, result is saved in matrix_1
*/
void    sub    (Matrix *matrix_1,
                Matrix *matrix_2);

/**
  Subtracts matrix_2 to matrix_1, result is returned
*/
Matrix *subc   (Matrix *matrix_1,
                Matrix *matrix_2);

/**
  Multiplies matrix_1 and matrix_2 with the naive method and then returns
  that matrix
*/
Matrix *mul    (Matrix *matrix_1,
                Matrix *matrix_2);

/**
  Compares two matrices, 1 is returned if both represent the same matrix. 0, if
  both represent different matrices
*/
int     equals (Matrix *matrix_1,
                Matrix *matrix_2);

/**
  Returns a string with the graphical representation of the matrix
*/
char   *str    (Matrix *matrix);

/**
  Frees all memory allocated
*/
void    del    (Matrix *matrix);

#endif
