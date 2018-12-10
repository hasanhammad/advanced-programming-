#ifndef MATRIX_2_H_INCLUDED
#define MATRIX_2_H_INCLUDED



#endif // MATRIX_2_H_INCLUDED
#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include <iostream>
#include <string>
class Matrix
{



    public:
     Matrix(int m , int n , int c ); // constructor 1 : makes a matrix with "m" rows and "n" columns and sets all the element to the default value "c"
     Matrix( int r  , int s ,char t ); // constructor 2 : makes a matrix with "r = m-1" rows and "s = s1" columns  so it makes a smaller matrix
     Matrix(int m , int n );// constructor 3 : makes a matrix with "m" rows and "n" columns and sets all the element to the value of "0"
     Matrix(int n );// constructor 4 : makes a matrix with "n" rows and "n" columns and sets all the element to the value of "0"
     Matrix();// constructor 5 : is an empty constructor
     void display( ) const ;// displays matrix
     double& AT(int i , int j ) const;// gets a specific element from the matrix
     inline int getRows() const// gets the number of rows of the wanted matrix
     {
        return m ;
     }
     inline int getCols()const// gets the number of columns of the wanted matrix
     {
        return n;
     }
     inline int getSize()const// gets the size of the wanted matrix
     {
        return m*n;
     }
     Matrix Add(const  Matrix &MATRIXB ) const;//return the sum of two matrices
     Matrix Add(double num  ) const;//return the sum of a matrix and a number
     Matrix subtract(const  Matrix &MATRIXB) const;// return the subtract of two matrices
     Matrix subtract(double num ) const;// return the subtract of a matrix and a number
     Matrix mult(const  Matrix &MATRIXB) const;// return the multiplication of two matrices
     Matrix mult (double num )const;// return the multiplication of a matrix and a number
     Matrix Transpose(const  Matrix &MATRIXB)const;//makes a Transpose matrix
     Matrix suBMatrix(const Matrix &MATRIXB, int r, int s, int p, int q)const;// return the sub matrix of a matrix considering the passed values
     void swapRows(int r1 , int r2 );// swaps two rows
     void linearCombination (double scalar , int r1 , int r2 );  // doing the linearCombination process considering the passed values
     void free (Matrix A);// to delete the matrix after finish using it
     double trace ();//doing the trace process

     double &operator()(int row, int col); //Overloading the parenthesis operator
     const double& operator()(int row, int col) const; //Overloading the parenthesis operator for constant objects

     friend std::ostream &operator<<( std::ostream &, const Matrix & ); //Overloading the << operator // cout>>some matrix
     friend std::istream &operator>>( std::istream &, Matrix &matrix ); //Overloading the >> operator // cin << some matrix

    private:
    double** matrix;
    int m ;// rows
    int n ; // columns
    int r ;// rows
    int s;// columns

};
Matrix operator + (const Matrix &matrix1, const Matrix &matrix2);//Overloading the "+" operator
Matrix operator * (const Matrix &matrix1, const Matrix &matrix2);//Overloading the "*" operator
Matrix operator - (const Matrix &matrix1, const Matrix &matrix2);//Overloading the "-" operator
Matrix operator ~ (const Matrix &matrix1);//Overloading the "~" operator
bool operator == (const Matrix &matrix1 ,const Matrix &matrix2) ; //Overloading the "==" operator
Matrix identity_matrix(int n);//makes an identity matrix
int ran_num (int x );//  return a random number
Matrix random_matrix(int m, int n);//makes a random matrix

#endif // MATRIX_H_INCLUDED
