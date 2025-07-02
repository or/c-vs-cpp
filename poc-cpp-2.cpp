#include <cstring>
#include <iostream>

// #define ALWAYS_INLINE __attribute__((always_inline))
#define ALWAYS_INLINE

class Matrix {
  public:
    unsigned int matrix[9];

    Matrix() { std::memset(matrix, 0, sizeof(unsigned int) * 9); }

    Matrix(const unsigned int data[9]) {
        std::memcpy(matrix, data, sizeof(unsigned int) * 9);
    }

    inline ALWAYS_INLINE void multiply(const Matrix &a, const Matrix &b) {
        matrix[0] = a.matrix[0] * b.matrix[0] + a.matrix[1] * b.matrix[3] +
                    a.matrix[2] * b.matrix[6];
        matrix[1] = a.matrix[0] * b.matrix[1] + a.matrix[1] * b.matrix[4] +
                    a.matrix[2] * b.matrix[7];
        matrix[2] = a.matrix[0] * b.matrix[2] + a.matrix[1] * b.matrix[5] +
                    a.matrix[2] * b.matrix[8];
        matrix[3] = a.matrix[3] * b.matrix[0] + a.matrix[4] * b.matrix[3] +
                    a.matrix[5] * b.matrix[6];
        matrix[4] = a.matrix[3] * b.matrix[1] + a.matrix[4] * b.matrix[4] +
                    a.matrix[5] * b.matrix[7];
        matrix[5] = a.matrix[3] * b.matrix[2] + a.matrix[4] * b.matrix[5] +
                    a.matrix[5] * b.matrix[8];
        matrix[6] = a.matrix[6] * b.matrix[0] + a.matrix[7] * b.matrix[3] +
                    a.matrix[8] * b.matrix[6];
        matrix[7] = a.matrix[6] * b.matrix[1] + a.matrix[7] * b.matrix[4] +
                    a.matrix[8] * b.matrix[7];
        matrix[8] = a.matrix[6] * b.matrix[2] + a.matrix[7] * b.matrix[5] +
                    a.matrix[8] * b.matrix[8];
    }
};

int main(int argc, char **argv) {
    Matrix matrix1((unsigned int[9]){1, 2, 3, 4, 5, 6, 7, 8, 9});
    Matrix matrix2((unsigned int[9]){9, 1, 8, 2, 7, 3, 6, 4, 5});
    Matrix temp;
    unsigned long total = 0;

    for (unsigned int i = 0; i < 10000000; i++) {
        temp.multiply(matrix1, matrix2);
        matrix1.multiply(matrix2, temp);
        matrix2.multiply(temp, matrix2);
        total += matrix2.matrix[5];
    }

    // std::cout << total << std::endl;
    return total;
}
