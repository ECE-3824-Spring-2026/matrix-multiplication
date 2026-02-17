
#include "../matrix.h"
#include <stdexcept>
using namespace std;

Matrix::Matrix(int r, int c, const float* input_data) {
    if (r <= 0 || c <= 0) {
        throw invalid_argument("Invalid matrix dimensions");
    }

    rows = r;
    cols = c;
    data = new float[rows * cols];

    if (input_data == nullptr) {
        for (int i = 0; i < rows * cols; ++i) {
            data[i] = 0.0f;
        }
        return;
    }

    for (int i = 0; i < rows * cols; ++i) {
        data[i] = input_data[i];
    }
}
Matrix::~Matrix() {
    if (data != nullptr) {
        delete[] data;
        data = nullptr;
    }
}
