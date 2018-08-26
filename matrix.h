#ifndef MATRIX_H_
#define MATRIX_H_

typedef struct _Matrix Matrix;

void    init  (Matrix **matrix,
               int      size);

void    set   (Matrix *matrix,
               int     i,
               int     j,
               int     value);

int     get   (Matrix *matrix,
               int     i,
               int     j);

void    add   (Matrix *matrix_1,
               Matrix *matrix_2);

void    sub   (Matrix *matrix_1,
               Matrix *matrix_2);

// Matrix *mul(Matrix *matrix_1,
//             Matrix *matrix_2);

void    print (Matrix *matrix);

void    del   (Matrix *matrix);

#endif
