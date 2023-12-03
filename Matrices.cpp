#include "Matrices.h"

namespace Matrices
{
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

    bool operator!=(const Matrix& a, const Matrix& b)
    {
        return !(a == b);
    }

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

    RotationMatrix::RotationMatrix(double theta)
    {
        Matrix::Matrix(2, 2);

        a(0, 0) = cos(theta);
        a(0, 1) = -sin(theta);
        a(1, 0) = sin(theta);
        a(1, 1) = cos(theta);
    }

    ScalingMatrix::ScalingMatrix(double scale)
    {
        Matrix::Matrix(2, 2);

        a(0, 0) = scale;
        a(0, 1) = 0;
        a(1, 0) = 0;
        a(1, 1) = scale;
    }

    TranslationMatrix::TranslationMatrix(double xShift, double yShift, int nCols)
    {
        Matrix::Matrix(2, nCols);

        for (int i = 0; i < 2; i++)
        {
            if (i = 0)
            {
                for (int j = 0; j < nCols; j++)
                {
                    a(i, j) = xShift;
                }
            }
            else if (i = 1)
            {
                for (int k = 0; k < nCols; k++)
                {
                    a(i, k) = yShift;
                }
            }
        }
    }
}