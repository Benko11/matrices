#include "matrix.h"
#include "stdlib.h"

matrix matrix_sum(matrix *m1, matrix *m2);
matrix matrix_diff(matrix *m1, matrix *m2);
matrix matrix_scalar_product(int scalar, matrix *m);
matrix matrix_product(matrix *m1, matrix *m2);
matrix identity_matrix(int n);

matrix matrix_sum(matrix *m1, matrix *m2) {
    if (m1->rows != m2->rows || m1->cols != m2->cols) {
        fputs("These matrices cannot be added", stderr);
        exit(EXIT_FAILURE);
    }

    matrix out, *sum;
    sum = &out;

    matrix_init(m1->rows, m1->cols, sum);

    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->cols; j++) {
            matrix_assign(i, j, matrix_get(i, j, m1) + matrix_get(i, j, m2), sum);
        }
    }

    return *sum;
}

matrix matrix_diff(matrix *m1, matrix *m2) {
    matrix diff = matrix_scalar_product(-1, m2);
    return matrix_sum(m1, &diff);
}

matrix matrix_scalar_product(int scalar, matrix *m) {
    matrix out, *product;
    product = &out;

    matrix_init(m->rows, m->cols, product);
    
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            double value = matrix_get(i, j, m);
            matrix_assign(i, j, scalar * value, product);
        }
    }

    return *product;
}

matrix matrix_product(matrix *m1, matrix *m2) {
    if (m1->cols != m2->rows) {
        fputs("These matrices cannot be multiplied\n", stderr);
        exit(EXIT_FAILURE);
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

matrix identity_matrix(int n) {
    if (n < 1) {
        fprintf(stderr, "Invalid matrix size");
        exit(EXIT_FAILURE);
    }

    matrix *identity;
    matrix_init(n, n, identity);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                matrix_assign(i, j, 1, identity);
                continue;
            }

            matrix_assign(i, j, 0, identity);
        }
    }

    return *identity;
}