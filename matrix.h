#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef MATRIX_H
#define MATRIX_H
typedef struct {
    int cols;
    int rows;
    double *values;
} matrix;

void matrix_init(int rows, int cols, matrix *matrix) {
    matrix->cols = cols;
    matrix->rows = rows;
    matrix->values = (double *) malloc(rows * cols * sizeof(double));
}

void matrix_assign(int row, int col, double value, matrix *matrix) {
    double *values = matrix->values;
    values += row * matrix->cols + col;
    *values = value;
}

int matrix_size(matrix *matrix) {
    return matrix->cols * matrix->rows;
}

void matrix_mass_assign(double *values, int length, matrix *matrix) {
    double *matrixValues = matrix->values;
    int actualLength = length;
    if (length > matrix_size(matrix)) {
        actualLength = matrix_size(matrix);
    }

    for (int i = 0; i < actualLength; i++) {
        *matrixValues++ = *values++;
    }
}

double matrix_get(int row, int col, matrix *matrix) {
    double *values = matrix->values;
    return *(values + row * matrix->cols + col);
}

double *matrix_get_row(int row, matrix *matrix) {
    double *found_row = (double *) malloc(matrix->cols * sizeof(double));
    double *aux = found_row;

    for (int i = 0; i < matrix->cols; i++) {
        *aux = matrix_get(row, i, matrix);
        aux++;
    }

    return found_row;
}

double *matrix_get_col(int col, matrix *matrix) {
    double *found_col = (double *) malloc(matrix->rows * sizeof(double));
    double *aux = found_col;

    for (int i = 0; i < matrix->rows; i++) {
        *aux = matrix_get(i, col, matrix);
        aux++;
    }

    return found_col;
}

void matrix_print(matrix *matrix) {
    double *values = matrix->values;
    for (int i = 0; i < matrix->rows; i++) {
        printf("[");
        for (int j = 0; j < matrix->cols; j++) {
            printf("%.1f", *values);
            values++;
            if (j != matrix->cols - 1) printf(", ");
        }
        puts("]");
    }
}

matrix matrix_transpose(matrix *original) {
    matrix out, *matrix_clone;
    matrix_clone = &out;
    
    matrix_init(original->cols, original->rows, matrix_clone);

    for (int i = 0; i < original->cols; i++) {
        for (int j = 0; j < original->rows; j++) {
            matrix_assign(i, j, matrix_get(j, i, original), matrix_clone);
        }
    }

    return *matrix_clone;
}

bool matrix_is_square(matrix *matrix) {
    return matrix->cols == matrix->rows;
}

double *matrix_trace(matrix *matrix) {
    if (!matrix_is_square(matrix)) return NULL;

    double *res;
    *res = 0;
    for (int i = 0; i < matrix->cols; i++) {
        printf("%f\n", matrix_get(i, i, matrix));
        *res += matrix_get(i, i, matrix);    
    }

    return res;
}

void matrix_free(matrix *matrix) {
    free(matrix->values);
}

#endif