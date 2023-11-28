#include "Matrices.h"

namespace Matrices
{
  // Constructor
  Matrix::Matrix(int _rows, int _cols)
  {
    rows = _rows;
    cols = _cols;

    a.resize(rows);
    for (size_t i = 0; i < rows; i++)
    {
      a.at(i).resize(cols, 0);        // Setting rows = cols and setting cols to 0
    }
  }

  // Add values in matrices together
  Matrix operator+(const Matrix& a, const Matrix& b)
  {
    if (a.getRows() != b.getRows() || a.getCols() != b.getCols())  // Rows have to equal cols
    {
      throw runtime_error("Error: dimensions must agree");
    }

    Matrix c(a.getRows(), b.getCols());

    for (int i = 0; i < a.getRows(); i++)
    {
      for (int j = 0; j < a.getCols(); j++)
      {
        c(i, j) = a(i, j) + b(i, j); 
      }
    }

    return c;
  }

  // Multiply values in matrices together
  Matrix operator*(const Matrix& a, const Matrix& b)
  {
    if (a.getCols() != b.getRows()) 
    {
      throw runtime_error("Error: dimensions must agree");
    }

    Matrix c(a.getRows(), b.getCols());

    for (int i = 0; i < a.getRows(); i++)
    {
      for (int j = 0; j < b.getCols(); j++)
      {
        for (int k = 0; k < a.getCols(); k++)
        {
          c(i, j) += a(i, k) * b(k, j);
        }
      }
    }
    
    return c;
  }

  // Check values in matrices to see if they're equal
  bool operator==(const Matrix& a, const Matrix& b)
  {
    bool equal;
    if (a.getRows() != b.getRows() && a.getCols() != b.getCols())
    {
      equal = false;
    }
    else
    {
      for (int i = 0; i < a.getRows(); i++)
      {
        for (int j = 0; j < a.getCols(); j++)
        {
          if (abs(a(i,j) - b(i,j)) < 0.001)
          {
            equal = true;
          }
          else
          {
            equal = false;
          }
        }
      }
    }

    return equal;
  }

  // Check values in matrices to see if they're not equal
  bool operator!=(const Matrix& a, const Matrix& b)
  {
    return !(a == b);
  }

  // Print out matrix
  ostream& operator<<(ostream& os, const Matrix& a)
  {
    for (int i = 0; i < a.getRows(); i++)
    {
      for (int j = 0; j < a.getCols(); j++)
      {
        os << setw(10) << a(i, j);
      }
      os << endl << endl;
    }

    return os;
  } 
} 
