#include<iostream>
#include"../matrix.h"

int main(){
    float v[] = {1,2,3,4};
    Matrix A(2,2,v);
    Matrix B = A + 4;
    
    cout << endl;

    cout << "Matrix A" << endl;
    A.display();

    cout << endl;

    cout << "Matrix B" << endl;
    B.display();

    cout << endl;

    cout << "A(1,1) = " << A(1,1) << endl;
    cout << "B(0,1) = " << B(0,1) << endl;

    cout << endl;

    A(1,0) = 1.1;
    cout << "Matrix A" << endl;
    A.display();

    cout << endl;
    cout << "Matrix C = A / 4.2" << endl;
    Matrix C = A / 4.2;
    C.display();

    cout << endl;
    cout << "Matrix D = A / 0.0" << endl;
    try{
        Matrix D = A / 0.0;
        D.display();
    }
    catch(domain_error& e){
        cout << "Error: " << e.what() << endl;
    }

    cout << endl;
    cout << "Add matrix A and B, same dims" << endl;
    C = A + B;
    C.display();

    cout << endl;
    cout << "Add matrix A and E, different dims" << endl;
    try{
        float w[] = {-1,-2};
        Matrix E(1,2,w);
        C = A + E;
        C.display();
    }
    catch(invalid_argument& e){
        cout << "Error: " << e.what() << endl; 
    }

    cout << endl;
    cout << "determinant of matrix A" << endl;
    A.display();
    cout << "det(A) = " << A.determinant();
    cout << endl;

}