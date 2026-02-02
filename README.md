# Matrix Library

```C++
class matrix{

}
```

<!-- ```C++
matrix x(2,3);  // create matrix of dimensions 2x3
x(0,0,1);       // manually assign each matrix element
x(0,1,2);
``` -->

## Matrix Creation
Create [[1,2,3],[4,5,6]] (2 rows, 3 columns)

```C++
float vals[][3] = {{1,2,3},{4,5,6}};
matrix x(2,3,vals);  // create matrix of dimensions 2x3
```

## Matrix Access

1,2,3<br>
4,5,6<br>
7,8,9

Note: all indexing starts with `0`

### Get value
```C++ 
float a = x(1,2);   // retrieve a value
// a = 6
```

### Get row
```C++
matrix a = x.getrow(1); // retrieve row #1
// a = matrix [4,5,6]
```

### Get column
```C++
matrix a = x.getcol(1); // retrieve col #1
// a = matrix [[2][5]]
```

### Get size
```C++
int n_rows = x.get_n_rows();
int n_cols = x.get_n_cols();
// n_rows = 3
// n_cols = 3
```

## 

* determinant
* rank
* add, subtract, multiply, divide
* factor(?)
* what kind of errors get thrown


## Matrix Transformations

### Transposition
```C++
matrix y = x.transpose();
```

### Inverse
```C++
matrix y = x.inverse();
```

