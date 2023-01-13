#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

const int MAX_SIZE = 20;


class Matrix 
{
    private:
        int data[MAX_SIZE][MAX_SIZE]; // Initialize maximum size of the matrix as 20x20
        int sizeOfMatrix;

    public:
        Matrix();
        Matrix(int size);
        Matrix(const Matrix& copyMatrix);
        
        virtual int getter(int row, int column) const; // obtain spesific row & column of the matrix Starts --> Row = 1, Column = 1.
        virtual void setter(int row, int column, int num_to_store); // Set value to the specific index of the matrix.
        virtual int getSize(void) const;
        unsigned virtual long hashCalculator(void);
        virtual void display_matrix(void) const; // Display matrix to show its index values.

        bool operator< (Matrix matrixCompare) const
        {
            if (this->sizeOfMatrix < matrixCompare.getSize())
            {
                return 1;
            }
            else if (this->sizeOfMatrix == matrixCompare.getSize())
            {
                for (int i = 0; i < this->sizeOfMatrix; i++)
                {
                    for (int j = 0; j < this->sizeOfMatrix; j++)
                    {
                        if (data[i][j] < matrixCompare.data[i][j])
                        {
                            return 1;
                        }
                    }
                }
                return 0;
            }
            else
            {
                return 0;
            }
        }
       
        bool operator== (Matrix matrixCompare) const
        {
            if (this->sizeOfMatrix == matrixCompare.getSize())
            {
                for (int i = 0; i < this->sizeOfMatrix; i++)
                {
                    for (int j = 0; j < this->sizeOfMatrix; j++)
                    {
                        if (data[i][j] != matrixCompare.data[i][j])
                        {
                            return 0;
                        }
                    }
                }
                return 1;
            }
            else
            {
                return 0;
            }
        }
};


Matrix::Matrix()
{
    sizeOfMatrix = 0;
}


Matrix::Matrix(int size)  // Initialize matrix with 0 entries.
{
    sizeOfMatrix = size;
    for (int i = 0; i < sizeOfMatrix; i++)
    {
        for (int j = 0; j < sizeOfMatrix; j++)
        {
            if (i == j)
            {
                data[i][j] = 1; // Set index values to 1 to create identity matrix.
            }
            else
            {
                data[i][j] = 0; // Set all remaining indexes of the matrix to 0.
            }
        }
    }
}


Matrix::Matrix(const Matrix& copyMatrix) 
{
    this->sizeOfMatrix = copyMatrix.sizeOfMatrix;
    for (int i = 0; i < sizeOfMatrix; i++)
    {
        for (int j = 0; j < sizeOfMatrix; j++)
        {
            this->data[i][j] = copyMatrix.data[i][j];
        }
    }
}


int Matrix::getter(int row, int column) const 
{
    row = row - 1; // Decrease by 1. Since given minimum row || column address will be 1 (i.e. row 1 = index 0). However, our min index for matrix starts from index 0;
    column = column - 1;

    if ((row < sizeOfMatrix) && (column < sizeOfMatrix) && (row >= 0) && (column >= 0)) 
    {
        return data[row][column]; // Obtain value from the specified address and return its value;
    }
    else 
    {
        cerr << "Row or column index is invalid !" << endl;
    }
}


void Matrix::setter(int row, int column, int num_to_store) 
{
    row = row - 1; // Decrease by 1. Since given minimum row || column address could be 1. However, our min index for matrix starts from index 0;
    column = column - 1;

    if ((row < sizeOfMatrix) && (column < sizeOfMatrix) && (row >= 0) && (column >= 0))
    {
        data[row][column] = num_to_store; // Store given number at the specified index;
    }
    else 
    {
        cerr << "Row or column index is invalid !" << endl;
    }
}


// To get size of the matrix, declare a function to find size
int Matrix::getSize(void) const
{
    return sizeOfMatrix;
}


unsigned long Matrix::hashCalculator(void)
{
    unsigned long hashValue = sizeOfMatrix;

    for (int i = 0; i < sizeOfMatrix; i++)
    {
        for (int j = 0; j < sizeOfMatrix; j++)
        {
            hashValue = 61 * hashValue + data[i][j];
        }
    }

    return hashValue % 65536; // take modulus to get value between 0 to 65535
}


// Display matrix to see values are placed correctly.
void Matrix::display_matrix(void) const 
{
    cout << "\n";
    for (int i = 0; i < sizeOfMatrix; i++)
    {
        for (int j = 0; j < sizeOfMatrix; j++)
        {
            cout << data[i][j] << "\t";
            if (j == sizeOfMatrix - 1)
            {
                cout << "\n";
            }
        }
    }
}

#endif