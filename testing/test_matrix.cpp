#include<iostream>
#include"../matrix.h"

int main(){
    float v[] = {1,2,3,4};
    Matrix A(2,2,v);
    A.display();
}