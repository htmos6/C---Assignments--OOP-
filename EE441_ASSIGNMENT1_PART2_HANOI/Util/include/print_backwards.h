////////////// QUESTION 2 //////////////
#include <iostream>
using namespace std;

void print_backwards(char const* string) {
    if (*string != '\0') {
        print_backwards(string + 1);
        cout << *string;
    }
}
