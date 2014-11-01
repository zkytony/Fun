#include <iostream>
#include "matrix.hpp"

using namespace std;

void printMatrix(int **ary, int r, int c)
{
  // alignment is a problem. Need to be smart to fix this
  for (int i = 0; i < r; i++)
    {
      cout << "[";
      for (int j = 0; j < c; j++)
        {
          cout << ary[i][j];
          if (j != c-1)
            {
              cout << " ";
            }
        }
      cout << "]" << endl;
    }
}

int** readMatrix()
{
  int r, c;
  cout << "Enter row (space) column: ";
  cin >> r >> c;
  int **ary = new int*[r];
  for (int i = 0; i < r; i++) 
    {
      ary[i] = new int[c];
      for (int j = 0; j < c; j++) 
        {
          cout << "Enter a number to [" << i << ", " << j << "]: ";
          cin >> ary[i][j];
        }
    }
  return ary;
}

// first try out two dimensional arrays
int main()
{
  Matrix A = Matrix::readMatrix("A");
  Matrix B = Matrix::readMatrix("B");
  cout << "Operation (1-+, 2-*, 3-T)";
  int op;
  cin >> op;
  if (op == 1)
    {
      Matrix C = A + B;
      C.print();
    }
  else if (op == 2)
    {
      Matrix C = A * B;
      C.print();
    }
  else if (op == 3)
    {
      Matrix C = A.transpose();
      Matrix D = B.transpose();
      cout << "Transpose of A" << endl;
      C.print();
      cout << "Transpose of B" << endl;
      D.print();
    }
  else
    {
      cout << "Wrong";
    }
}