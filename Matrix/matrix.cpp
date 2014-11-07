#include "matrix.hpp"
#include <iostream>
#include <string>
#include <math.h> // log10

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

// returns the number of digits of an integer
int num_digit(int n)
{
  int number = 0;
  if (n < 0)
    {
      number++;
    }
  while (n != 0)
    {
      n = n / 10;
      number++;
    }
  return number;
}

// prints the matrix with good alignment
void Matrix::print()
{  
  int *col_longest = new int[c];
  int **diff = new int*[r];
  // first construct the 2d array of diff;
  for (int i = 0; i < r; i++)
    {
      diff[i] = new int[c];
    }

  for (int j = 0; j < c; j++)
    {
      for (int i = 0; i < r; i++)
        {
          int digits = num_digit(m_arr[i][j]);
          if (digits > col_longest[j])
            {
              col_longest[j] = digits;
            }
        }

      // this loop computes the diff of length of each 
      // cell to the longest one
      for (int i = 0; i < r; i++)
        {
          int digits = num_digit(m_arr[i][j]);
          diff[i][j] = col_longest[j] - digits;
        }
    }

  // finally print it out
  for (int i = 0; i < r; i++)
    {
      cout << "[";
      for (int j = 0; j < c; j++)
        {
          // print spaces
          for (int k = 0; k < diff[i][j]; k++)
            {
              cout << " ";
            }
          cout << m_arr[i][j];
          if (j != (c-1))
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

// takes in indices of two rows and swap them
Matrix Matrix::swaprow_new(int r1, int r2)
{
  int **ary = new int*[r];
  for (int i = 0; i < r; i++) 
    {
      ary[i] = new int[c];
      for (int j = 0; j < c; j++) 
        {
          if (i == r1)
            {
              ary[i][j] = m_arr[r2][j];
            }
          else if (i == r2)
            {
              ary[i][j] = m_arr[r1][j];
            }
          else
            {
              ary[i][j] = m_arr[i][j];
            }
        }
    }
  Matrix result = Matrix(ary, r, c);
  return result;
}

// swap the rows without producing another matrix
void Matrix::swaprow(int r1, int r2)
{
  int *temp = m_arr[r1];
  m_arr[r1] = m_arr[r2];
  m_arr[r2] = temp;
}














