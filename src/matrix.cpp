matrix matrix::operator+(float k) const {
    matrix result(rows, cols);
    for (int i = 0; i < rows * cols; i++)
        result.data[i] = data[i] + k;
    return result;
}

matrix matrix::operator-(float k) const {
    matrix result(rows, cols);
    for (int i = 0; i < rows * cols; i++)
        result.data[i] = data[i] - k;
    return result;
}

matrix matrix::operator*(float k) const {
    matrix result(rows, cols);
    for (int i = 0; i < rows * cols; i++)
        result.data[i] = data[i] * k;
    return result;
}

matrix matrix::operator/(float k) const {
    if (k == 0.0f)
        throw std::domain_error("Divide by zero");

    matrix result(rows, cols);
    for (int i = 0; i < rows * cols; i++)
        result.data[i] = data[i] / k;
    return result;
}