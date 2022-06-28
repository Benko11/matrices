#include "matrix.h"
#include "stdlib.h"

matrix matrix_product(matrix *m1, matrix *m2) {
    if (m1->cols != m2->rows) {
        fputs("These matrices cannot be multiplied\n", stderr);
        exit(EXIT_SUCCESS);
    }

    matrix out, *product;
    product = &out;

    matrix_init(m1->rows, m2->cols, product);

    for (int i = 0; i < m1->rows; i++) {
        double *matrix_row = matrix_get_row(i, m1);

        for (int j = 0; j < m2->cols; j++) {
            double *matrix_col = matrix_get_col(j, m2);

            double *aux_row = matrix_row;
            double *aux_col = matrix_col;

            double sum = 0;
            for (int k = 0; k < m1->cols; k++) {
                sum += *aux_row * *aux_col;
                aux_row++;
                aux_col++;
            }

            matrix_assign(i, j, sum, product);
        }
    }

    return *product;
}