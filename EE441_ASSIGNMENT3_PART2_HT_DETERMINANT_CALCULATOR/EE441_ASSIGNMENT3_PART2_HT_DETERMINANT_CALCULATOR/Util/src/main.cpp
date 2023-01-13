#include "MatrixFunctions.h"
#include "Matrix.h"
#include "HashItem.h"
#include "HashTable.h"
#include "ReadMatrix.h"
#include <chrono>

int main()
{
    HT_Table hashT;
    Matrix readMtrxHT;

    long det;
    int timeElapsedHT = 0;
    long long int memoryUsed = 0;

    // Hash Table File Reading
    for (int i = 11; i <= 15; i++)
    {
        for (int j = 0; j <= 4; j++)
        {
            auto start = std::chrono::high_resolution_clock::now();
            HT_Table* ptrHashT = new HT_Table;

            readMtrxHT = ReadMatrix(i, j);
            det = ptrHashT->determinantHT(readMtrxHT, i);

            readMtrxHT.display_matrix();

            cout << endl << "Matrix Size: " << i << "x" << i << endl;
            cout << "File Name : " << j << ".txt" << endl;

            cout << "Determinant of the Matrix: " << det << endl;

            cout << "Filled Capacity of the Hash Table: " << ptrHashT->count << endl;
            cout << "Size of HT_Table in bytes: " << sizeof(HT_Table) * ptrHashT->count << " bytes" << endl;

            delete ptrHashT;

            auto stop = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

            cout << "Time Elapsed: " << duration.count() / 1000 << " miliseconds" << endl;
            timeElapsedHT = timeElapsedHT + (int)(duration.count() / 1000);
            memoryUsed += sizeof(HT_Table) * (ptrHashT->count);
        }
    }

    cout << "\nAverage HT time elapsed: " << timeElapsedHT / 25 << " miliseconds" << endl;
    cout << "Average Memory Used in Bytes: " << (memoryUsed / 25) << " bytes" <<endl;

    return 0;
}
