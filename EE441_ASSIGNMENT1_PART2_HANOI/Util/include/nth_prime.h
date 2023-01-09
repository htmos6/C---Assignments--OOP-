////////////// QUESTION 3 //////////////
#include <iostream>
using namespace std;

bool check_prime(int num) {
    if (num == 0 || num == 1) {
        return false;
    }
    else {
        for (int i=2; i<=num/2; i++) {
            if (!(num % i)) {
                return false;
            }
        }
        return true;
    }
}


int nth_prime(int n) {
    int num = 0;
    int counter = 0;

    while (counter < n) {
        if (check_prime(num)) {
            counter += 1;
            if (counter == n) {
                return num;
            }
            num += 1;
        }
        else {
            num += 1;
        }
    }
};

