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
private:
  int **m_arr;
  int r, c;
};

#endif


















