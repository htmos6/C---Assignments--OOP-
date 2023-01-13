#include <fstream>
#include <sstream>
#include <string>
#include "Matrix.h"

Matrix ReadMatrix(int sizeOfMatrix, int fileNo)
{
    // i.e. Form of the matrice file path --> matricesFilePath = "C:/Users/Legion/Desktop/C++ projects/Assignment3/PA3/PA3/Util/matrices";
    ifstream input_file;

    Matrix resultMatrix(sizeOfMatrix);
    string txtFilePath = "C:/Users/Legion/Desktop/Assignment3-Part2/Assignment3-Part2/matrices";

    int valueMtr;

    txtFilePath += '/' + to_string(sizeOfMatrix) + '/' + to_string(fileNo) + ".txt";
    input_file.open(txtFilePath);

    for (int i = 1; i <= sizeOfMatrix; i++)
    {
        for (int j = 1; j <= sizeOfMatrix; j++)
        {
            input_file >> valueMtr;
            resultMatrix.setter(i, j, valueMtr);
        }
    }

    input_file.close();
    return resultMatrix;
}
