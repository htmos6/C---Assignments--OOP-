#include "BinarySearchTree.h"
#include "MatrixFunctions.h"
#include "Matrix.h"
#include "ReadMatrix.h"

#include <chrono>


int main()
{
    Matrix readMtrxBT;
    Matrix readMtrxHT;

    long det;
    int timeElapsedBT = 0;
    int memoryUsed = 0;

    // Binary Tree File Reading
    for (int i = 11; i <= 15; i++)
    {
        for (int j = 0; j <= 4; j++)
        {
            totalNode = 0;
            auto start = std::chrono::high_resolution_clock::now();

            BST_Node* ptrNodeBT = new BST_Node;

            readMtrxBT = ReadMatrix(i, j);
            det = ptrNodeBT->determinantBT(readMtrxBT, i, ptrNodeBT);

            readMtrxBT.display_matrix();
            cout << endl << "Matrix Size: " << i << "x" << i << endl;
            cout << "File Name : " << j << ".txt" << endl;

            cout << "Determinant of the Matrix: " << det << endl;

            cout << "Number of BST_Node: " << totalNode << " BST_Node" << endl;
            cout << "Size of BST_Node in bytes: " << sizeof(BST_Node) * totalNode << " bytes" << endl;

            delete ptrNodeBT;

            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

            cout << "Time Elapsed: " << duration.count()/1000 << " miliseconds" << endl;
            timeElapsedBT = timeElapsedBT + (int)(duration.count() / 1000);
            memoryUsed += sizeof(BST_Node) * totalNode;
        }
    }

    cout << "\nAverage BT time elapsed: " << timeElapsedBT / 25 << " miliseconds" << endl;
    cout << "\nAverage Memory Used in Bytes: " << (memoryUsed / 25) << " bytes" <<endl;

    return 0;
}
