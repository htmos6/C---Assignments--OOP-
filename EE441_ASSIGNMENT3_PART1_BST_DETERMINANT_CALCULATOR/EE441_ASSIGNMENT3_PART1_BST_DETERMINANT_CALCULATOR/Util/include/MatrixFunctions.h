#include "Matrix.h"

#ifndef MATRIXFUNCTIONS_H
#define MATRIXFUNCTIONS_H


Matrix addition(Matrix mtr1, Matrix mtr2) 
{
    int sizeOfMatrix = mtr1.getSize();
    int temp;
    
    Matrix resultAddMatrix(sizeOfMatrix);

    // Travel through both matrix. Add their same address values to each other and store inside another matrix.
    for (int i = 0; i < sizeOfMatrix; i++)
    {
        for (int j = 0; j < sizeOfMatrix; j++)
        {
            resultAddMatrix.setter(i + 1, j + 1, 0);
            temp = mtr1.getter(i + 1, j + 1) + mtr2.getter(i + 1, j + 1);
            resultAddMatrix.setter(i + 1, j + 1, temp);
        }
    }
    return resultAddMatrix;
}


Matrix subtraction(Matrix mtr1, Matrix mtr2)
{
    int sizeOfMatrix = mtr1.getSize();
    int temp;

    Matrix resultSubsMatrix(sizeOfMatrix);

    // Travel through both matrix. Subtract their same address values from each other and store inside another matrix.
    for (int i = 0; i < sizeOfMatrix; i++)
    {
        for (int j = 0; j < sizeOfMatrix; j++)
        {
            resultSubsMatrix.setter(i + 1, j + 1, 0);
            temp = mtr2.getter(i + 1, j + 1) - mtr1.getter(i + 1, j + 1);
            resultSubsMatrix.setter(i + 1, j + 1, temp);
        }
    }
    return resultSubsMatrix;
}


// Travel Through each matrix and apply matrix multiplication rule.
// Algorithm for the foor loop designed accordingly.
Matrix multiplication(Matrix mtr1, Matrix mtr2)
{      
    int sizeOfMatrix = mtr1.getSize();
    int temp;

    Matrix resultMultpMatrix(sizeOfMatrix);

    for (int i = 0; i < sizeOfMatrix; i++)
    {
        for (int j = 0; j < sizeOfMatrix; j++)
        {
            resultMultpMatrix.setter(i + 1, j + 1, 0);
            temp = 0;
            for (int z = 0; z < sizeOfMatrix; z++)
            {
                temp += mtr1.getter(i + 1, z + 1) * mtr2.getter(z + 1, j + 1);
            }
            resultMultpMatrix.setter(i + 1, j + 1, temp);
        }
    }
    return resultMultpMatrix;
}


int determinant(Matrix matr, int sizeOfMatrix)
{
    int i_sub_mtr = 0;
    int j_sub_mtr = 0;
    int result = 0;

    Matrix temp_matr(sizeOfMatrix-1);

    if (sizeOfMatrix == 1)
    {
        return matr.getter(1, 1);
    }
    else if (sizeOfMatrix == 2)
    {
        return matr.getter(1, 1) * matr.getter(2, 2) - matr.getter(1, 2) * matr.getter(2, 1);
    }

    for (int i = 0; i < sizeOfMatrix; i++) // Close each column successively to calculate determinant
    {
        i_sub_mtr = 0;
        for (int j = 1; j < sizeOfMatrix; j++) // do not include row 0 in the det calculation
        {
            j_sub_mtr = 0;
            for (int k = 0; k < sizeOfMatrix; k++) // change your column address
            {
                if (k == i) // If closed column and travelling column are meet, pass current loop.
                {
                    continue;
                }
                temp_matr.setter(i_sub_mtr + 1, j_sub_mtr + 1, matr.getter(j + 1, k + 1)); // Give index values as incremented by 1. Since minimum number of row || column number should be 1.
                j_sub_mtr += 1;
            }
            i_sub_mtr += 1;
        }
        result += (determinant(temp_matr, sizeOfMatrix - 1) * matr.getter(1, i + 1) * pow(-1, i)); // Call determinant by recursively. Store result inside result variable.
    }
    return result;
}

#endif