#include <iostream>
using namespace std;

// Consider negative indexing at getter method
// Delete display matrix function

template <int N>
class Matrix {
private:
    double data[N][N];

public:
    Matrix();
    int const SIZE = N; // specify size of the matrix
    double getter(int row, int column) const; // obtain spesific row & column of the matrix Starts --> Row = 1, Column = 1;
    void setter(int row, int column, double num_to_store); // Set value to the specific index of the matrix
    void display_matrix(void) const; // Print matrix to show its index values
};


template <int N> // Make matrix identity.
Matrix<N>::Matrix() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                data[i][j] = 1; // if row == column , set its value to 1 to obtain identity matrix.
            }
            else {
                data[i][j] = 0;
            }
        }
    }
}

template <int N>
double Matrix<N>::getter(int row, int column) const {
    row = row - 1; // Decrease by 1. Since given minimum row || column address could be 1. However, our min index for matrix starts from index 0;
    column = column - 1;
    if ((row < N & column < N) & (row >= 0 & column >= 0)) {
        return data[row][column]; // Obtain value from the specified address and return its value;
    }
    else {
        cerr << "Row or column Type is Invalid !" << endl;
    }
}

template <int N>
void Matrix<N>::setter(int row, int column, double num_to_store) {
    row = row - 1; // Decrease by 1. Since given minimum row || column address could be 1. However, our min index for matrix starts from index 0;
    column = column - 1;
    if ((row < N & column < N) & (row >= 0 & column >= 0)) {
        data[row][column] = num_to_store; // Store given number at the specified index;
    }
    else {
        cerr << "Row or column Type is Invalid !" << endl;
    }
}

template <int N> // Display matrix to see values are placed correctly.
void Matrix<N>::display_matrix(void) const {
    cout << "\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << data[i][j] << " ";
            if (j == N - 1) {
                cout << "\n";
            }
        }
    }
}




/////////// OUT OF CLASS FUNCTIONS ///////////
template <int N>
Matrix<N> addition(Matrix<N> mtr1, Matrix<N> mtr2) {
    Matrix<N> result_add;
    double temp;
    // Travel through both matrix. Add their same address values to each other and store inside another matrix.
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            result_add.setter(i + 1, j + 1, 0);
            temp = mtr1.getter(i + 1, j + 1) + mtr2.getter(i + 1, j + 1);
            result_add.setter(i + 1, j + 1, temp);
        }
    }
    return result_add;
}


template <int N>
Matrix<N> subtraction(Matrix<N> mtr1, Matrix<N> mtr2)
{
    Matrix<N> result_subs;
    double temp;
    // Travel through both matrix. Subtract their same address values from each other and store inside another matrix.
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            result_subs.setter(i + 1, j + 1, 0);
            temp = mtr2.getter(i + 1, j + 1) - mtr1.getter(i + 1, j + 1);
            result_subs.setter(i + 1, j + 1, temp);
        }
    }
    return result_subs;
}


template <int N>
Matrix<N> multiplication(Matrix<N> mtr1, Matrix<N> mtr2)
{       // Travel Through each matrix and apply matrix multiplication rule.
        // Algorithm for the foor loop designed accordingly.
    Matrix<N> result_mult;
    double temp;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            result_mult.setter(i + 1, j + 1, 0);
            temp = 0;
            for (int z = 0; z < N; z++)
            {
                temp += mtr1.getter(i + 1, z + 1) * mtr2.getter(z + 1, j + 1);
            }
            result_mult.setter(i + 1, j + 1, temp);
        }
    }
    return result_mult;
}


double determinant(Matrix<1> matr) // If N = 1, this function will run. Function overwrite is used.
{
    return matr.getter(1, 1);
}


double determinant(Matrix<2> matr)  // If N = 2, this function will run. Function overwrite is used.
{
    return matr.getter(1, 1) * matr.getter(2, 2) - matr.getter(1, 2) * matr.getter(2, 1);
}


template <int N>
double determinant(Matrix<N> matr)
{
    int i_sub_mtr = 0;
    int j_sub_mtr = 0;
    int result = 0;
    Matrix<N - 1> temp_matr;

    for (int i = 0; i < N; i++) // Close each column successively to calculate determinant
    {
        i_sub_mtr = 0;
        for (int j = 1; j < N; j++) // do not include row 0 in the det calculation
        {
            j_sub_mtr = 0;
            for (int k = 0; k < N; k++) // change your column address
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
        result += (determinant(temp_matr) * matr.getter(1, i + 1) * pow(-1, i)); // Call determinant by recursively. Store result inside result variable.
    }
    return result;
}






