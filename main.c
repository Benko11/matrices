#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

int main(int argc, char const *argv[]) {
    matrix out, *m;
    m = &out;

    double arr[] = {2, 7, 1, 4, 8, -1, 1, 11, 9, 55, 30};
    matrix_init(2, 3, m);
    matrix_mass_assign(arr, sizeof(arr) / sizeof(double), m);
    matrix_print(m);
    matrix t = matrix_transpose(m);
    matrix_print(&t);

    matrix_free(m);
    matrix_free(&t);

    return EXIT_SUCCESS;
}
