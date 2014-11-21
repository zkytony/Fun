#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <string>

class Matrix
{
public:
  Matrix();
  Matrix(int **arr, int r, int c);
  int get(int r, int c);
  int num_row();
  int num_col();
  Matrix operator+(Matrix);
  Matrix operator*(Matrix);
  Matrix transpose();
  void print();
  static Matrix readMatrix(std::string name);
  Matrix swaprow_new(int r1, int r2);
  void swaprow(int r1, int r2);
  Matrix minor(int r_m, int c_m);
  int det();
private:
  int **m_arr;
  int r, c;
  int det(int i, int j);
};

#endif
