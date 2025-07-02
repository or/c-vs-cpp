#include <stdio.h>

// #define ALWAYS_INLINE __attribute__((always_inline))
#define ALWAYS_INLINE

static inline ALWAYS_INLINE void
multiply(unsigned int *result, const unsigned int *a, const unsigned int *b) {
    result[0] = a[0] * b[0] + a[1] * b[3] + a[2] * b[6];
    result[1] = a[0] * b[1] + a[1] * b[4] + a[2] * b[7];
    result[2] = a[0] * b[2] + a[1] * b[5] + a[2] * b[8];
    result[3] = a[3] * b[0] + a[4] * b[3] + a[5] * b[6];
    result[4] = a[3] * b[1] + a[4] * b[4] + a[5] * b[7];
    result[5] = a[3] * b[2] + a[4] * b[5] + a[5] * b[8];
    result[6] = a[6] * b[0] + a[7] * b[3] + a[8] * b[6];
    result[7] = a[6] * b[1] + a[7] * b[4] + a[8] * b[7];
    result[8] = a[6] * b[2] + a[7] * b[5] + a[8] * b[8];
}

int main(int argc, char **argv) {
    unsigned int matrix1[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    unsigned int matrix2[9] = {9, 1, 8, 2, 7, 3, 6, 4, 5};
    unsigned int temp[9];
    unsigned long total = 0;
    unsigned int i;

    for (i = 0; i < 10000000; i++) {
        multiply(temp, matrix1, matrix2);
        multiply(matrix1, matrix2, temp);
        multiply(matrix2, temp, matrix2);
        total += matrix2[5];
    }

    // printf("%lu\n", total);
    return total;
}
