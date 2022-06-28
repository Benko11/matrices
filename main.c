#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
#include "operations.h"

int main(int argc, char const *argv[]) {
    matrix out, *m1;
    m1 = &out;

    matrix out2, *m2;
    m2 = &out2;

    double arr1[] = {1, 2, 4, 2, 6, 0};
    double arr2[] = {4, 1, 4, 3, 0, -1, 3, 1, 2, 7, 5, 2};
    
    matrix_init(2, 3, m1);
    matrix_init(3, 4, m2);
    matrix_mass_assign(arr1, 6, m1);
    matrix_mass_assign(arr2, 12, m2);

    matrix product = matrix_product(m1, m2);
    matrix_print(&product);

    matrix_free(m1);
    matrix_free(m2);
    matrix_free(&product);

    return EXIT_SUCCESS;
}
