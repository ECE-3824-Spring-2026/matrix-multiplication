// AI tool: ChatGPT

#include "../matrix.h"
#include <stdexcept>
#include <cstdio>

static void check_dims(int r, int c) {
    if (r <= 0 || c <= 0) throw std::invalid_argument("invalid dimensions");
}

static void check_idx(int i, int j, int r, int c) {
    if (i < 0 || j < 0 || i >= r || j >= c) throw std::logic_error("index out of bounds");
}

static int at(int i, int j, int cols) { return i * cols + j; }

Matrix::Matrix(int r, int c, const float* input)
    : rows(r), cols(c), data(nullptr)
{
    check_dims(rows, cols);
    data = new float[rows * cols];
    if (!input) {
        for (int k = 0; k < rows * cols; ++k) data[k] = 0.0f;
    } else {
        for (int k = 0; k < rows * cols; ++k) data[k] = input[k];
    }
}

Matrix::Matrix(const Matrix& other)
    : rows(other.rows), cols(other.cols), data(nullptr)
{
    check_dims(rows, cols);
    data = new float[rows * cols];
    for (int k = 0; k < rows * cols; ++k) data[k] = other.data[k];
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) return *this;
    float* nd = new float[other.rows * other.cols];
    for (int k = 0; k < other.rows * other.cols; ++k) nd[k] = other.data[k];
    delete[] data;
    data = nd;
    rows = other.rows;
    cols = other.cols;
    return *this;
}

Matrix::~Matrix() {
    delete[] data;
    data = nullptr;
}

const float& Matrix::operator()(int i, int j) const {
    if (!data) throw std::logic_error("uninitialized");
    check_idx(i, j, rows, cols);
    return data[at(i, j, cols)];
}

float& Matrix::operator()(int i, int j) {
    if (!data) throw std::logic_error("uninitialized");
    check_idx(i, j, rows, cols);
    return data[at(i, j, cols)];
}

int Matrix::get_n_rows() const { return rows; }
int Matrix::get_n_cols() const { return cols; }

void Matrix::display() const {
    if (!data) throw std::logic_error("uninitialized");
    for (int r = 0; r < rows; ++r) {
        std::printf("[ ");
        for (int c = 0; c < cols; ++c) {
            std::printf("%g", (*this)(r, c));
            if (c + 1 < cols) std::printf(", ");
        }
        std::printf(" ]\n");
    }
}

bool Matrix::operator==(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) return false;
    for (int k = 0; k < rows * cols; ++k) {
        if (data[k] != other.data[k]) return false;
    }
    return true;
}

Matrix Matrix::transpose() const {
    if (!data) throw std::logic_error("uninitialized");
    float* t = new float[rows * cols];
    for (int r = 0; r < rows; ++r)
        for (int c = 0; c < cols; ++c)
            t[at(c, r, rows)] = (*this)(r, c);
    Matrix out(cols, rows, t);
    delete[] t;
    return out;
}

static void require_same_shape(const Matrix& A, const Matrix& B) {
    if (A.get_n_rows() != B.get_n_rows() || A.get_n_cols() != B.get_n_cols())
        throw std::invalid_argument("incompatible dimensions");
}

Matrix Matrix::operator+(const Matrix& other) const {
    if (!data || !other.data) throw std::logic_error("uninitialized");
    require_same_shape(*this, other);
    float* v = new float[rows * cols];
    for (int i = 0; i < rows * cols; ++i) v[i] = data[i] + other.data[i];
    Matrix out(rows, cols, v);
    delete[] v;
    return out;
}

Matrix Matrix::operator-(const Matrix& other) const {
    if (!data || !other.data) throw std::logic_error("uninitialized");
    require_same_shape(*this, other);
    float* v = new float[rows * cols];
    for (int i = 0; i < rows * cols; ++i) v[i] = data[i] - other.data[i];
    Matrix out(rows, cols, v);
    delete[] v;
    return out;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (!data || !other.data) throw std::logic_error("uninitialized");
    if (cols != other.rows) throw std::invalid_argument("incompatible dimensions");
    float* v = new float[rows * other.cols];
    for (int i = 0; i < rows * other.cols; ++i) v[i] = 0.0f;

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < other.cols; ++c) {
            float s = 0.0f;
            for (int k = 0; k < cols; ++k) s += (*this)(r, k) * other(k, c);
            v[at(r, c, other.cols)] = s;
        }
    }
    Matrix out(rows, other.cols, v);
    delete[] v;
    return out;
}

Matrix Matrix::operator+(const float& k) const {
    if (!data) throw std::logic_error("uninitialized");
    float* v = new float[rows * cols];
    for (int i = 0; i < rows * cols; ++i) v[i] = data[i] + k;
    Matrix out(rows, cols, v);
    delete[] v;
    return out;
}

Matrix Matrix::operator-(const float& k) const {
    if (!data) throw std::logic_error("uninitialized");
    float* v = new float[rows * cols];
    for (int i = 0; i < rows * cols; ++i) v[i] = data[i] - k;
    Matrix out(rows, cols, v);
    delete[] v;
    return out;
}

Matrix Matrix::operator*(const float& k) const {
    if (!data) throw std::logic_error("uninitialized");
    float* v = new float[rows * cols];
    for (int i = 0; i < rows * cols; ++i) v[i] = data[i] * k;
    Matrix out(rows, cols, v);
    delete[] v;
    return out;
}

Matrix Matrix::operator/(const float& k) const {
    if (!data) throw std::logic_error("uninitialized");
    if (k == 0.0f) throw std::domain_error("divide by zero");
    float* v = new float[rows * cols];
    for (int i = 0; i < rows * cols; ++i) v[i] = data[i] / k;
    Matrix out(rows, cols, v);
    delete[] v;
    return out;
}

float Matrix::determinant() const {
    if (!data) throw std::logic_error("uninitialized");
    if (rows != cols) throw std::invalid_argument("determinant requires square");
    if (rows == 1) return (*this)(0,0);
    if (rows == 2) return (*this)(0,0) * (*this)(1,1) - (*this)(0,1) * (*this)(1,0);

    float det = 0.0f;
    for (int j = 0; j < cols; ++j) {
        float* minor = new float[(rows - 1) * (cols - 1)];
        int p = 0;
        for (int r = 1; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (c == j) continue;
                minor[p++] = (*this)(r, c);
            }
        }
        Matrix M(rows - 1, cols - 1, minor);
        delete[] minor;
        float sign = (j % 2 == 0) ? 1.0f : -1.0f;
        det += sign * (*this)(0, j) * M.determinant();
    }
    return det;
}

int Matrix::rank() const {
    if (!data) throw std::logic_error("uninitialized");
    if (rows == 0 || cols == 0) return 0;

    int n = rows, m = cols;
    float* t = new float[n * m];
    for (int i = 0; i < n * m; ++i) t[i] = data[i];

    auto absf = [](float x) { return x < 0.0f ? -x : x; };
    const float EPS = 1e-6f;

    int r = 0, rk = 0;
    for (int c = 0; c < m && r < n; ++c) {
        int piv = r;
        for (int rr = r + 1; rr < n; ++rr)
            if (absf(t[at(rr, c, m)]) > absf(t[at(piv, c, m)])) piv = rr;

        if (absf(t[at(piv, c, m)]) < EPS) continue;

        if (piv != r) {
            for (int cc = 0; cc < m; ++cc) {
                float tmp = t[at(r, cc, m)];
                t[at(r, cc, m)] = t[at(piv, cc, m)];
                t[at(piv, cc, m)] = tmp;
            }
        }

        float pv = t[at(r, c, m)];
        for (int rr = 0; rr < n; ++rr) {
            if (rr == r) continue;
            float f = t[at(rr, c, m)] / pv;
            for (int cc = c; cc < m; ++cc)
                t[at(rr, cc, m)] -= f * t[at(r, cc, m)];
        }

        ++r;
        ++rk;
    }

    delete[] t;
    return rk;
}
