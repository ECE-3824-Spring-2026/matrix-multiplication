#include<vector>
using namespace std;

class Matrix{
    private:
    int rows;
    int cols;
    vector<float> vals;

    public:

    Matrix(int,int,const float*);           // constructor
    Matrix& operator=(const Matrix&);       // copy assignment A = B
    ~Matrix();                              // destructor

    const float& operator()(int,int) const; // enables float x = A(1,2) -> data retrieval
    float& operator()(int i, int j);        // enables A(1,2) = 3.14 -> data assignment

    int get_n_rows() const;                 // return number of rows
    int get_n_cols() const;                 // return number of columns
    float determinant() const;              // return matrix determinant
    int rank() const;                       // return matrix rank
    void display() const;                   // display formatted matrix

    Matrix transpose() const;                   // B = A.transpose

    Matrix operator+( const Matrix& ) const;    // add Matrix plus Matrix
    Matrix operator-( const Matrix& ) const;
    Matrix operator*( const Matrix& ) const;
    Matrix operator+( const float& )  const;    // add constant to Matrix
    Matrix operator-( const float& )  const;
    Matrix operator*( const float& )  const;
    Matrix operator/( const float& )  const;

};