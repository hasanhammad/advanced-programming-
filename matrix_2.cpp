 #include <iostream>
 #include"matrix_2.h"
 #include <ctime>
 #include <cstdlib>
 #include <iomanip>
 #include <vector>
#include <cassert>
 using namespace std ;



    Matrix::Matrix(int m , int n , int c ) // constructor 1 : makes a matrix with "m" rows and "n" columns and sets all the element to the default value "c"
    :m(m),n(n)
    {
    matrix = new double*[m];
    for (int i = 0; i < m; ++i)
    matrix[i] = new double[n];

    for (int i =0 ; i < m ; i ++)
      {
       for (int j = 0 ; j < n ; j++)
         {
          matrix[i][j]= c;
         }
      }
    }

    Matrix::Matrix( int r  , int s ,char t ) // constructor 2 : makes a matrix with "r = m-1" rows and "s = s1" columns  so it makes a smaller matrix
     :m(r-1),n(s-1)
    {
    matrix = new double*[m];
    for (int i = 0; i < m ; ++i)
    matrix[i] = new double[n];
    }


    Matrix::Matrix(int m , int n ) // constructor 3 : makes a matrix with "m" rows and "n" columns and sets all the element to the value of "0"
    :m(m),n(n)
    {
      matrix = new double*[m];
      for (int i = 0; i < m; ++i)
      matrix[i] = new double[n];

    for (int i =0 ; i < m ; i ++)
      {
       for (int j = 0 ; j < n ; j++)
         {
           matrix[i][j]= 0;
         }
      }

    }

    Matrix::Matrix(int n )// constructor 4 : makes a matrix with "n" rows and "n" columns and sets all the element to the value of "0"
    :m(n),n(n)
    {

    matrix = new double*[n];
    for (int i = 0; i < n; ++i)
    matrix[i] = new double[n];

    for (int i =0 ; i < n ; i ++)
      {
      for (int j = 0 ; j < n ; j++)
        {
         matrix[i][j]= 0;
        }
      }

    }



     Matrix::Matrix()// constructor 5 : is an empty constructor
     :m(0),n(0)
     {


     }


    void Matrix::display( ) const // displays matrix
        {
         for (int i =0 ; i < m ; i ++)
           {
            for (int j = 0 ; j < n; j++)
              {
                cout<<setw(10)<<setprecision( 2 )<<fixed;
                cout<<matrix[i][j]<<" ";
              }
            cout<<endl;
           }
        }

    double& Matrix::AT(int i , int j ) const // gets a specific element from the matrix
    {
        return matrix[i][j];
    }


    Matrix Matrix::Add(const  Matrix &MATRIXB ) const //return the sum of two matrices
    {
       Matrix f(m ,n); // f is a new matrix used in this function
       int MATRIXB_rows=MATRIXB.getRows(); // the number of the rows of the passed matrix
       int MATRIXB_cols=MATRIXB.getCols();// the number of the columns of the passed matrix

        if (m == MATRIXB_rows && n==MATRIXB_cols )
         {
            for (int i =0 ; i < MATRIXB_rows ; i++)
              {
               for(int j =0 ; j < MATRIXB_cols ; j++)
                 {

                  f.AT(i,j)= MATRIXB.AT(i,j) +  matrix[i][j];

                 }
               }

         }
        else
            cout<<"can not be done !"<<endl;
        return f;

}
      Matrix Matrix::Add(double num  ) const //return the sum of a matrix and a number
      {

       Matrix f(m ,n); // f is a new matrix used in this function

       int MATRIXB_rows=f.getRows();// the number of the rows of the  matrix  f
       int MATRIXB_cols=f.getCols();// the number of the columns of the  matrix  f

        for (int i =0 ; i < MATRIXB_rows ; i++)
          {
            for(int j =0 ; j < MATRIXB_cols ; j++)
              {
                f.AT(i,j)= num +  matrix[i][j];
              }
          }
        return f;
      }

  Matrix Matrix::subtract(const  Matrix &MATRIXB) const // return the subtract of two matrices
  {
       Matrix f(m ,n);// f is a new matrix used in this function

   int MATRIXB_rows=MATRIXB.getRows();// the number of the rows of the passed matrix
   int MATRIXB_cols=MATRIXB.getCols();// the number of the columns of the passed matrix


    if ( m == MATRIXB_rows && n==MATRIXB_cols  ) // the condition of the subtract process
     {
        for (int i =0 ; i < MATRIXB_rows ; i++)
          {
           for(int j =0 ; j < MATRIXB_cols ; j++)
             {
              f.AT(i,j)=  matrix[i][j]- MATRIXB.AT(i,j);// doing the subtract process
             }
          }

     }
    else
        cout<<"can not be done !"<<endl;
    return f;

  }

      Matrix Matrix::subtract(double num ) const // return the subtract of a matrix and a number
      {
          Matrix f(m ,n);// f is a new matrix used in this function
       int MATRIXB_rows=f.getRows();// the number of the rows of the matrix f
       int MATRIXB_cols=f.getCols();// the number of the columns of the  matrix  f

        for (int i =0 ; i < MATRIXB_rows ; i++)
          {
            for(int j =0 ; j < MATRIXB_cols ; j++)
              {

                f.AT(i,j)= matrix[i][j] -  num ; // doing the subtract process
              }
          }
        return f;
      }

  Matrix Matrix::mult(const  Matrix &MATRIXB) const // return the multiplication of two matrices
  {
   int MATRIXB_rows=MATRIXB.getRows();// the number of the rows of the passed matrix
   int MATRIXB_cols=MATRIXB.getCols();// the number of the columns of the passed matrix
   ;

   Matrix f(MATRIXB_rows ,MATRIXB_cols); // f is a new matrix used in this function
    if (n == MATRIXB_rows )  // the condition of the multiplication  process
    {
        for (int i =0 ; i < m ; i++)
         {
           for(int j =0 ; j < MATRIXB_cols ; j++)
            {
              f.AT(i,j) = 0 ;
              for (int k =0 ; k< MATRIXB_rows ; k++)
               {
                  f.AT(i,j) += matrix[i][k] * MATRIXB.AT(k,j); // doing the multiplication  process

               }


            }
        }

    }
    else
        cout<<"can not be done !"<<endl;
    return f;

  }

  Matrix Matrix::mult (double num ) const // return the multiplication of a matrix and a number
  {
      Matrix f(m ,n);// f is a new matrix used in this function
   int MATRIXB_rows=f.getRows();// the number of the rows of the matrix f
   int MATRIXB_cols=f.getCols();// the number of the columns of the  matrix  f

    for (int i =0 ; i < MATRIXB_rows ; i++)
      {
        for(int j =0 ; j < MATRIXB_cols ; j++)
          {
            f.AT(i,j)= matrix[i][j] *  num ; // doing the multiplication  process
          }
      }
    return f;
  }

  Matrix Matrix::Transpose(const  Matrix &MATRIXB) const //makes a Transpose matrix
  {
      int MATRIXB_rows=MATRIXB.getRows();// the number of the rows of the passed matrix
      int MATRIXB_cols=MATRIXB.getCols();// the number of the columns of the passed matrix
      Matrix f(MATRIXB_cols ,MATRIXB_rows);// f is a new matrix used in this function

      for(int i =0 ; i <MATRIXB_rows; i++ )
        {
          for(int j =0 ; j <MATRIXB_cols ; j++)
            {
               f.AT(j,i) = matrix[i][j]; // doing the transpose process
            }
        }
      return f;
  }

    Matrix Matrix::suBMatrix(const Matrix &MATRIXB, int r, int s, int p, int q) const // return the sub matrix of a matrix considering the passed values
    {
        Matrix mat1 ( r , s  ); // mat1 is a new matrix used in this function
        Matrix mat2 ( r , s , 'h' ) ; // mat2 is a new matrix used in this function " made by the second constructor "
        vector<double> g1; //define a vector
        int cntr1 = p ; //  the number of the row
        int cntr2 = q ;//  the  number of the column
        int MATRIXB_rows=MATRIXB.getRows();// the number of the rows of the passed matrix
        int MATRIXB_cols=MATRIXB.getCols();// the number of the columns of the passed matrix
        int MAT1_rows=mat1 .getRows();// the number of the rows of the  matrix mat1
        int MAT1_cols=mat1 .getCols();// the number of the columns of the  matrix mat1
        int MAT2_rows=mat2.getRows();// the number of the rows of the  matrix mat2
        int MAT2_cols=mat2.getCols();// the number of the columns of the  matrix mat2

    for ( int i = 0; i < MATRIXB_rows; i++ )
       {

        for ( int j =0 ; j < MATRIXB_cols ; j++ )
          {
           if (i == cntr1 || j == cntr2)
            {
             mat1.AT(i , j) = -99999999999 ; //exclusion the unwanted elements by setting their values to  -99999999999
            }
           else
              {
                mat1.AT(i , j) = MATRIXB.AT(i ,j);
              }


            }
       }

       for ( int i = 0; i < MAT1_rows ; i++ )
         {
          for ( int j =0 ; j < MAT1_cols ; j++ )
            {
             if (  mat1.AT(i , j) !=  -99999999999  )
              {
                g1.push_back(mat1.AT(i , j)); // putting the values in the vector exception the unwanted values
              }
            }
       }
                   int v = 0 ;

        for ( int i = 0; i < MAT2_rows ; i++ )
          {
            for ( int j =0 ; j < MAT2_cols ; j++ )
              {
                mat2.AT( i , j ) = g1[v] ;  // putting the values in mat2 matrix "the matrix that will be returned "
                   v++;
               }
          }

    return mat2 ;
    }


    void Matrix::swapRows(int row1 , int row2 ) // swaps two rows
    {

     if (row1 < m && row2 < m) //  the swap condition
     {
      for (int i = 0 ; i < n ; i++) // doing the swap process
        {
            double temp =  matrix[row1][i];
            matrix[row1][i] =  matrix[row2][i];
            matrix[row2][i] = temp ;
        }
    }
      else
      {
          cout<<"can not be done !"<<endl;
      }


    }

    void Matrix::linearCombination (double scalar , int row1 , int row2 ) // doing the linearCombination process considering the passed values
    {
        if (row1 < m && row2 < m) //  the swap condition
        {
         for (int i = 0 ; i < n ; i++) // doing the linearCombination process
           {
             double temp ;
             temp = matrix[row1][i] * scalar ;
             matrix[row2][i] = temp ;

         }
        }
        else
      {
          cout<<"can not be done !"<<endl;
      }

    }



    void Matrix::free (Matrix A) // to delete the matrix after finishing of  using it
    {
     for( int i = 0; i < A.n; i++ )
        {
         delete [] A.matrix[i];
        }
         delete [] A.matrix;
         A.matrix = NULL;
    }



    double Matrix::trace () //doing the trace process
    {
        double trace =0;
        for (int i = 0 ; i < n ; i++)
            {
             trace = trace + matrix[i][i];
            }

            return trace ;
    }

   double &Matrix::operator()(int row, int col)
    {
        if ( (col >= 0 && col < n) && (row >= 0 && row < m) )
        {
         return matrix[row][col];
        }

        else
        {
            cout<<"out of range !"<<endl;
        }

     }



    const double& Matrix::operator()(int row, int col) const //Overloading the parenthesis operator
    {
        if ( (col >= 0 && col < n) && (row >= 0 && row < m) ) // to make sure that the wanted element exists in the matrix
        {
         return matrix[row][col];
        }

        else
        {
            cout<<"this element does not exist in the matrix (out of the range !) "<<endl;
        }
    } // end function operator "()"






      ostream &operator<<( ostream &output, const Matrix &matrix ) //Overloading the << operator  "cout << some Matrix "
       {
        for (int i =0 ; i < matrix.m ; i ++)
           {
            for (int j = 0 ; j < matrix.n; j++)
              {
                output<<setw(10)<<setprecision( 2 )<<fixed;
                output<<matrix.AT(i,j)<<" ";
              }
            output<<endl;
           }

        return output;

       } // end function operator "<< "

    istream &operator>>( istream &input, Matrix &matrix ) //Overloading the >> operator  "cin  >> some Matrix "
    {

       cout<<"please enter the number of rows :";
       cin>>matrix.m;
        cout<<"please enter the number of columns :";
        cin>>matrix.n ;
        for (int i =0 ; i < matrix.m ; i++)
           {
            for (int j = 0 ; j <matrix.n; j++)
              {

               input>>matrix.AT(i,j);


              }

           }

return input;
    } // end function operator ">>"


////// end of the class

    Matrix identity_matrix(int n)//makes an identity matrix

        {
            Matrix f(n); //f is a matrix used in this function
            for (int i = 0 ; i < n ; i++)
              {
                f.AT(i,i)= 1;
              }
             return f;
        }

    int ran_num (int x ) //  return a random number
    {
        int i;
        i = (rand()%x);

        return i ;
    }

       Matrix random_matrix(int m, int n) //makes a random matrix
       {
       Matrix f(m , n); // f is a new matrix used in this function
      srand((unsigned)time(0));
      for (int i =0 ; i < m ; i ++)
        {
        for (int j = 0 ; j < n ; j++)
          {
            f.AT(i,j)= ran_num(10);
          }
        }

      return f;
     }


      Matrix operator + (const Matrix &matrix1, const Matrix &matrix2)//Overloading the "+" operator
    {
       int MATRIX1_rows=matrix1.getRows();// the number of the rows of the  matrix1
       int MATRIX1_cols=matrix1.getCols();// the number of the columns of the  matrix1
       int MATRIX2_rows=matrix2.getRows();// the number of the rows of the  matrix2
       int MATRIX2_cols=matrix2.getCols();// the number of the columns of the  matrix2

       if (  (MATRIX1_rows==MATRIX2_rows) && (MATRIX1_cols==MATRIX2_cols)  ) // the condition of addition process
       {
           Matrix matrix3 (MATRIX1_rows,MATRIX1_cols);// matrix 3 is a new matrix used in this function
        for (int i =0 ; i < MATRIX1_rows ; i++)
          {
            for(int j =0 ; j < MATRIX1_cols ; j++)
              {
                matrix3.AT(i,j)= matrix1.AT(i , j) +  matrix2.AT(i , j); // doing the addition process
              }
          }
        return matrix3;
       }
       else // if the addition  process can not be done ;
       {
           cout<<"the addition process can not be done !"<<endl; // print this message
       }


    } // end function operator "+"


      Matrix operator * (const Matrix &matrix1, const Matrix &matrix2)  //Overloading the "*" operator // multiplication some matrices
    {
       int MATRIX1_rows=matrix1.getRows();// the number of the rows of the  matrix1
       int MATRIX1_cols=matrix1.getCols();// the number of the columns of the  matrix1
       int MATRIX2_rows=matrix2.getRows();// the number of the rows of the  matrix2
       int MATRIX2_cols=matrix2.getCols();// the number of the columns of the  matrix2

       Matrix matrix3 (MATRIX1_rows,MATRIX2_cols);// matrix 3 is a new matrix used in this function
        if (MATRIX1_cols == MATRIX2_rows )  // the condition of the multiplication  process
        {
            for (int i =0 ; i < MATRIX1_rows ; i++)
             {
               for(int j =0 ; j < MATRIX2_cols ; j++)
                {
                    matrix3.AT(i ,j) = 0;
                  for (int k =0 ; k< MATRIX2_rows ; k++)
                   {
                      matrix3.AT(i ,j) += matrix1.AT(i , k) * matrix2.AT(k , j); // doing the multiplication  process

                   }


                }
            }

        }
        else // if the multiplication process can not be done ;
        {
            cout<<"can not be done !"<<endl;
        }

        return matrix3;


    }// end function operator "*"

     Matrix operator - (const Matrix &matrix1, const Matrix &matrix2) //Overloading the "-" operator
        {
           int MATRIX1_rows=matrix1.getRows();// the number of the rows of the  matrix1
           int MATRIX1_cols=matrix1.getCols();// the number of the columns of the  matrix1
           int MATRIX2_rows=matrix2.getRows();// the number of the rows of the  matrix2
           int MATRIX2_cols=matrix2.getCols();// the number of the columns of the  matrix2

           if (  (MATRIX1_rows==MATRIX2_rows) && (MATRIX1_cols==MATRIX2_cols)  ) // the condition of the subtraction
           {
               Matrix matrix3 (MATRIX1_rows,MATRIX1_cols);// matrix 3 is a new matrix used in this function
            for (int i =0 ; i < MATRIX1_rows ; i++)
              {
                for(int j =0 ; j < MATRIX1_cols ; j++)
                  {
                    matrix3.AT(i,j)= matrix1.AT(i , j) -  matrix2.AT(i , j); // doing the subtraction  process
                  }
              }
            return matrix3;
           }
           else // if the subtraction process can not be done ;
           {
               cout<<"the subtraction process can not be done !"<<endl; // print this message
           }



        } // end function operator "-"


    Matrix operator ~ (const Matrix &matrix1) //Overloading the "~" operator  // transpose some matrix
    {
       int MATRIX1_rows=matrix1.getRows();// the number of the rows of the  matrix1
       int MATRIX1_cols=matrix1.getCols();// the number of the columns of the  matrix1


           Matrix matrix2 (MATRIX1_cols,MATRIX1_rows);// matrix 2 is a new matrix used in this function
        for (int i =0 ; i < MATRIX1_rows ; i++)
          {
            for(int j =0 ; j < MATRIX1_cols ; j++)
              {
                matrix2.AT(j,i)= matrix1.AT(i , j);//replacing elements
              }
          }
        return matrix2;

    } // end function operator "~"

    bool operator == (const Matrix &matrix1 ,const Matrix &matrix2) //Overloading the "==" operator
    {
       int MATRIX1_rows=matrix1.getRows();// the number of the rows of the  matrix1
       int MATRIX1_cols=matrix1.getCols();// the number of the columns of the  matrix1
       int MATRIX2_rows=matrix2.getRows();// the number of the rows of the  matrix2
       int MATRIX2_cols=matrix2.getCols();// the number of the columns of the  matrix2
        if (  (MATRIX1_rows==MATRIX2_rows) && (MATRIX1_cols==MATRIX2_cols)  ) // checking if the columns and rows of the first array are equal to the columns and rows of the second array
        {
            for (int i = 0 ; i < MATRIX1_rows ; i++ )
            {
                for (int j = 0 ; j < MATRIX1_cols ; j++ )
                {
                    if (matrix1.AT(i,j) != matrix2.AT(i,j))
                    {
                        return false ;
                    }

                }
            }
        }
        else { return false ;}
    }
