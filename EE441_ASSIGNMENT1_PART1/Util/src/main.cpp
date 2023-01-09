#include "main.h"
#include <math.h>

int main() {

    Matrix<3> a;
    Matrix<3> b;

    a.setter(1, 1, 5);
    a.setter(1, 2, 2);
    a.setter(1, 3, 6);
    a.setter(2, 1, 0);
    a.setter(2, 2, 6);
    a.setter(2, 3, 2);
    a.setter(3, 1, 3);
    a.setter(3, 2, 8);
    a.setter(3, 3, 1);


    b.setter(1, 1, 7);
    b.setter(1, 2, 5);
    b.setter(1, 3, 8);
    b.setter(2, 1, 1);
    b.setter(2, 2, 8);
    b.setter(2, 3, 2);
    b.setter(3, 1, 9);
    b.setter(3, 2, 4);
    b.setter(3, 3, 3);

    a.display_matrix();
    cout << endl;

    b.display_matrix();


    Matrix<3> c = multiplication<3>(a, b);
    c.display_matrix();

    double det;
    det = determinant(a);
    cout << endl << "Determinant of the matrix a: " << det;

    return 0;
}



