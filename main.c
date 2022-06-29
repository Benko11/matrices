#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
#include "operations.h"

int main(int argc, char const *argv[]) {
    matrix out, *m1;
    m1 = &out;

    matrix out2, *m2;
    m2 = &out2;

    double arr1[] = {-1, 0, 2, 3};
    double arr2[] = {1, 2, 3, 0};
    
    matrix_init(2, 2, m1);
    matrix_init(2, 2, m2);
    matrix_mass_assign(arr1, 4, m1);
    matrix_mass_assign(arr2, 4, m2);

    matrix sum = matrix_sum(m1, m2);
    matrix_print(&sum);
    matrix_free(&sum);

    matrix diff = matrix_diff(m1, m2);
    matrix_print(&diff);
    matrix_free(&diff);


    matrix scalar_product = matrix_scalar_product(-3, m1);
    matrix_print(&scalar_product);

    matrix identity = identity_matrix(5);
    matrix_print(&identity);

    matrix_free(m1);
    matrix_free(m2);
    matrix_free(&scalar_product);

    return EXIT_SUCCESS;
}
