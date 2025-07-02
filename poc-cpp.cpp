#include <cstring>
#include <iostream>

// #define ALWAYS_INLINE __attribute__((always_inline))
#define ALWAYS_INLINE

class Matrix {
  private:
    unsigned int matrix[9];

  public:
    Matrix() { std::memset(matrix, 0, sizeof(unsigned int) * 9); }

    Matrix(const unsigned int data[9]) {
        std::memcpy(matrix, data, sizeof(unsigned int) * 9);
    }

    inline ALWAYS_INLINE void multiply(const Matrix &a, const Matrix &b) {
        matrix[0] = a[0] * b[0] + a[1] * b[3] + a[2] * b[6];
        matrix[1] = a[0] * b[1] + a[1] * b[4] + a[2] * b[7];
        matrix[2] = a[0] * b[2] + a[1] * b[5] + a[2] * b[8];
        matrix[3] = a[3] * b[0] + a[4] * b[3] + a[5] * b[6];
        matrix[4] = a[3] * b[1] + a[4] * b[4] + a[5] * b[7];
        matrix[5] = a[3] * b[2] + a[4] * b[5] + a[5] * b[8];
        matrix[6] = a[6] * b[0] + a[7] * b[3] + a[8] * b[6];
        matrix[7] = a[6] * b[1] + a[7] * b[4] + a[8] * b[7];
        matrix[8] = a[6] * b[2] + a[7] * b[5] + a[8] * b[8];
    }

    inline ALWAYS_INLINE const unsigned int &
    operator[](std::size_t index) const {
        return matrix[index];
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
        total += matrix2[5];
    }

    // std::cout << total << std::endl;
    return total;
}
