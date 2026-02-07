#include "../matrix.h"

// Compare two matrices for equality
bool Matrix::operator==(const Matrix& other) const {
    // Check size first
    if (get_n_rows() != other.get_n_rows() || get_n_cols() != other.get_n_cols()) {
        return false;
    }

    // Check each element
    for (int i = 0; i < get_n_rows(); ++i) {
        for (int j = 0; j < get_n_cols(); ++j) {
            if ((*this)(i, j) != other(i, j)) {
                return false;
            }
        }
    }

    return true;
}