#include "matrix.hpp"
#include <iostream>
#include <string>

using namespace std;

Matrix::Matrix(int **arr, int r, int c)
  :m_arr(arr), r(r), c(c)
{

}


int Matrix::get(int r, int c)
{
  return m_arr[r][c];
}

int Matrix::num_row()
{
  return r;
}

int Matrix::num_col()
{
  return c;
}

Matrix Matrix::operator+(Matrix other)
{
  try
    {
      if (r != other.r || c != other.c)
        {
          throw 99;
        }
      else {
        int **new_arr = new int*[r];
        for (int i = 0; i < r; i++)
          {
            new_arr[i] = new int[c];
            for (int j = 0; j < c; j++)
              {
                new_arr[i][j] = get(i,j) + other.get(i,j);
              }
          }
        Matrix result = Matrix(new_arr, r, c);
        return result;
      }
    } catch (int x) {
    cerr << "ERROR " << x << " invalid input format: addition requires same dimension of two matrices" << endl;
  }
}

// Matrix multiplication: naive method
Matrix Matrix::operator*(Matrix other)
{
  try
    {
      if (c != other.num_row())
        {
          throw 99;
        }
      else
        {
          int **new_arr = new int*[r];
          for (int i = 0; i < r; i++)
            {
              new_arr[i] = new int[other.num_col()];
              for (int j = 0; j < other.num_col(); j++)
                {
                  int sum = 0;
                  for (int k = 0; k < c; k++)
                    {
                      sum += get(i,k) * other.get(k,j);
                    }
                  new_arr[i][j] = sum;
                }
            }
          Matrix result = Matrix(new_arr, r, other.num_col());
          return result;
        }
    }
  catch (int x)
    {
      cerr << "ERROR " << x << " invalid input format: multiplication requires nxc and cxm" << endl;
    }
}

Matrix Matrix::transpose()
{
  int **new_arr = new int*[c];
  for (int j = 0; j < c; j++)
    {
      new_arr[j] = new int[r];
      for (int i = 0; i < this-> num_row(); i++)
        {
          new_arr[j][i] = this->get(i,j);
        }
    }
  Matrix result = Matrix(new_arr, c, r);
  return result;
}

void Matrix::print()
{
    // alignment is a problem. Need to be smart to fix this
  for (int i = 0; i < r; i++)
    {
      cout << "[";
      for (int j = 0; j < c; j++)
        {
          cout << this->get(i,j);
          if (j != c-1)
            {
              cout << " ";
            }
        }
      cout << "]" << endl;
    }
}

Matrix Matrix::readMatrix(string name)
{
  int r, c;
  cout << "Inputing for matrix " << name << endl;
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
  Matrix result = Matrix(ary, r, c);
  return result;
}
