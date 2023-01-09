#include <iostream>
using namespace std;

class Disc {
private:
    int discs[20]; // Declare an disc[20] array to hold discs at the order of ascending radius. Ex: discs[0] = 1, discs[1] = 2;
public:
    Disc(int d); // Fill disc array according to given number of disc. Disc diameters start from 1 & increases by 1;
    Disc() : discs() {}; // Declare an default constructor since Disc class inherits. Additionally, when Hanoi constructor is initialized;
    // Disc class's (base class's default constructor of the Hanoi) default constructor is called automatically;
    // If default constructor does not exist, error message is displayed;

    int getDisc(int discNo) const; // Declare a getDisc method in order to grab discs according to their diameter values. Then we place them to corresponding Rods;
};

class Hanoi : public Disc {
private:
    int num_of_disc; // Num of disc exist in Hanoi that we are playing;
    int Rod0[20];
    int Rod1[20];
    int Rod2[20];
    int counter0 = -1; // Start counter0 from 0. It will always show last index of the Rod0 which has a disc if counter0 != -1;
    int counter1 = -1; // Start counter1 from 0. It will always show last index of the Rod1 which has a disc if counter1 != -1;
    int counter2 = -1; // Start counter2 from 0. It will always show last index of the Rod2 which has a disc if counter2 != -1;

public:
    Hanoi(int n); // Declare an constructor for Hanoi class.
    int getNumOfDisc(void) const; // In order to solve & play Hanoi game,  we will need a total number of discs exists in the Rods;
    void moveRod(int from, int to); // Function defined in order to move discs from RodX to RodY;
    void dispRods(void) const; // In order to debug & examine desired rods;
    void printMovedRods(int discNo, int rodFrom, int rodTo) const; // To display moving discs. It will make code more clear.
};


// Disc Class Declarations //
Disc::Disc(int d) {  // Disc constructor. According to given number of disc that will be used at the Hanoi game, discs are placed to "discs array";
    // It holds discs at the order of ascending radius. Ex: discs[0] = 1, discs[1] = 2;
    if (d > 0 && d <= 20) // Check if Disc number is valid;
    {
        for (int i = 19; i >= 0; i--)
        {
            if (i < d)
            {
                discs[i] = i + 1; // Fill disc array with i+1 value. (i+1) comes from design algorithm Ex: discs[0] = 1, discs[1] = 2;
            }
            else
            {
                discs[i] = 0; // If it is not desired range, fill array with 0 means that it is empty;
            }
        }
    }
    else
    {
        cerr << "Invalid disc number !" << endl;
        exit(1);
    }
};


int Disc::getDisc(int discNo) const { // In order to grab disc from array and place it to rods. It return diameter of the desired disc;
    return discs[discNo - 1];
};


Hanoi::Hanoi(int n) {
    Disc discs(n); // Call disc constructor. When object from hanoi is called, it should prepare disc array to be used while filling source Rod;
    num_of_disc = n; // Store disc number inside a variable. It will be used in order to solve Hanoi Game;

    if (n > 0 && n <= 20)
    {
        for (int i = 19; i >= 0; i--) {
            if (i >= n) {
                Rod0[i] = discs.getDisc(i + 1); // Grab desired disc from disc array. Place it to the rod.
            }
            else {
                counter0 += 1;
                Rod0[i] = discs.getDisc(n - i);  // Grab desired disc from disc array. Place it to the rod.
            }
            Rod1[i] = 0; // Auxilary rod is empty at the beginning.
            Rod2[i] = 0; // Destination rod is empty at the beginning.
        }
    }
    else
    {
        cerr << "Invalid disc number !" << endl;;
    }
};


// <Below function is implemented in order to move discs from one location to another location> //
// <Firstly it checks whether the destination location is available. If counterX == 19, destination rod is full> //
// <For the destination register counterX should also be larger or equal than -1. "-1" means that X Rod is empty> //
// <Above explanation is enough for the (if) & (else if) statements of the "to X" Rod conditions> //

void Hanoi::moveRod(int from, int to) {
    if (to == 0 && counter0 >= -1 && counter0 < 19) // Check destination has a space to put disc.
    {
        if (from == 1 && counter1 >= 0 && counter1 <= 19) // <Check source rod is not empty> //
        {
            if (Rod1[counter1] < Rod0[counter0] || counter0 == -1) // <Check coming disc has smaller radius than disc existing at the destination> //
            {   // <Since destination counter shows index which is full, increase it by 1. Also if it is empty, counter = -1, increase by 1. Shows first index> //
                // <Decrease counter of the source Rod since total number of disc is decreased by one at that rod> //
                counter0 += 1;
                Rod0[counter0] = Rod1[counter1];
                printMovedRods(Rod1[counter1], 1, 0);
                Rod1[counter1] = 0;
                counter1 -= 1;
            }
            else
            {
                cerr << "Invalid move !" << endl;
                exit(1);
            }
        }
        else if (from == 2 && counter2 >= 0 && counter2 <= 19) // <Check source rod is not empty> //
        {
            if (Rod2[counter2] < Rod0[counter0] || counter0 == -1) // <Check coming disc has smaller radius than disc existing at the destination> //
            {   // <Since destination counter shows index which is full, increase it by 1. Also if it is empty, counter = -1, increase by 1. Shows first index> //
                // <Decrease counter of the source Rod since total number of disc is decreased by one at that rod> //
                counter0 += 1;
                Rod0[counter0] = Rod2[counter2];
                printMovedRods(Rod2[counter2], 2, 0);
                Rod2[counter2] = 0;
                counter2 -= 1;
            }
            else
            {
                cerr << "Invalid move !" << endl;
                exit(1);
            }
        }
        else
        {
            cerr << "Invalid move !" << endl;
            exit(1);
        }
    }

    else if (to == 1 && counter1 >= -1 && counter1 < 19) // Check destination has a space to put disc.
    {
        if (from == 0 && counter0 >= 0 && counter0 <= 19) // <Check source rod is not empty> //
        {
            if (Rod0[counter0] < Rod1[counter1] || counter1 == -1)  // <Check coming disc has smaller radius than disc existing at the destination> //
            {   // <Since destination counter shows index which is full, increase it by 1. Also if it is empty, counter = -1, increase by 1. Shows first index> //
                // <Decrease counter of the source Rod since total number of disc is decreased by one at that rod> //
                counter1 += 1;
                Rod1[counter1] = Rod0[counter0];
                printMovedRods(Rod0[counter0], 0, 1);
                Rod0[counter0] = 0;
                counter0 -= 1;
            }
            else
            {
                cerr << "Invalid move !" << endl;
                exit(1);
            }
        }
        else if (from == 2 && counter2 >= 0 && counter2 <= 19) // <Check source rod is not empty> //
        {
            if (Rod2[counter2] < Rod1[counter1] || counter1 == -1)  // <Check coming disc has smaller radius than disc existing at the destination> //
            {   // <Since destination counter shows index which is full, increase it by 1. Also if it is empty, counter = -1, increase by 1. Shows first index> //
                // <Decrease counter of the source Rod since total number of disc is decreased by one at that rod> //
                counter1 += 1;
                Rod1[counter1] = Rod2[counter2];
                printMovedRods(Rod2[counter2], 2, 1);
                Rod2[counter2] = 0;
                counter2 -= 1;
            }
            else
            {
                cerr << "Invalid move !" << endl;
                exit(1);
            }
        }
        else
        {
            cerr << "Invalid move !" << endl;
            exit(1);
        }
    }

    else if (to == 2 && counter2 >= -1 && counter2 < 19) // Check destination has a space to put disc.
    {
        if (from == 0 && counter0 >= 0 && counter0 <= 19) // <Check source rod is not empty> //
        {
            if (Rod0[counter0] < Rod2[counter2] || counter2 == -1)  // <Check coming disc has smaller radius than disc existing at the destination> //
            {   // <Since destination counter shows index which is full, increase it by 1. Also if it is empty, counter = -1, increase by 1. Shows first index> //
                // <Decrease counter of the source Rod since total number of disc is decreased by one at that rod> //
                counter2 += 1;
                Rod2[counter2] = Rod0[counter0];
                printMovedRods(Rod0[counter0], 0, 2);
                Rod0[counter0] = 0;
                counter0 -= 1;
            }
            else
            {
                cerr << "Invalid move !" << endl;
                exit(1);
            }
        }
        else if (from == 1 && counter1 >= 0 && counter1 <= 19) // <Check source rod is not empty> //
        {
            if (Rod1[counter1] < Rod2[counter2] || counter2 == -1)  // <Check coming disc has smaller radius than disc existing at the destination> //
            {   // <Since destination counter shows index which is full, increase it by 1. Also if it is empty, counter = -1, increase by 1. Shows first index> //
                // <Decrease counter of the source Rod since total number of disc is decreased by one at that rod> //
                counter2 += 1;
                Rod2[counter2] = Rod1[counter1];
                printMovedRods(Rod1[counter1], 1, 2);
                Rod1[counter1] = 0;
                counter1 -= 1;
            }
            else
            {
                cerr << "Invalid move !" << endl;
                exit(1);
            }
        }
        else
        {
            cerr << "Invalid move !" << endl;
            exit(1);
        }
    }

    else
    {
        cerr << "Invalid target rod !";
        exit(1);
    }

};


// <Look at the content of the rods. Which diameter sizes exist at each rod> //
void Hanoi::dispRods() const {

    cout << endl << "Rod 0: ";
    for (int i = 0; i < 20; i++)
    {
        cout << Rod0[i] << " ";
    }

    cout << endl << "Rod 1: ";
    for (int i = 0; i < 20; i++)
    {
        cout << Rod1[i] << " ";
    }

    cout << endl << "Rod 2: ";
    for (int i = 0; i < 20; i++)
    {
        cout << Rod2[i] << " ";
    }

    cout << endl;
};


void Hanoi::printMovedRods(int discNo, int rodFrom, int rodTo) const { // To display moving discs. It will make code more clear.
    cout << endl << "Disc " << discNo << " is moved from Rod " << rodFrom << " to Rod " << rodTo;
};


int Hanoi::getNumOfDisc(void) const { // In order to solve & play Hanoi game,  we will need a total number of discs exists in the Rods;
    return num_of_disc;
};


// Recursive function in order to be used to solve Hanoi Game.
void hanoiRecursive(Hanoi& game, int ct, int from, int to, int aux)
{
    if (ct == 1) // If you have 1 disc remaining, move it to the destination;
    {
        game.moveRod(from, to);
        // game.dispRods(); // Look at the content of the rods.
        return;
    }
    hanoiRecursive(game, ct - 1, from, aux, to); // According to Hanoi solving algorithm, set & change Source, Destination & Aux. rods numbers. Duties of the rods are changed;
    game.moveRod(from, to); // Move function to carry discs
    // game.dispRods(); // Look at the content of the rods.
    hanoiRecursive(game, ct - 1, aux, to, from); // According to Hanoi solving algorithm, set & change Source, Destination & Aux. rods numbers. Duties of the rods are changed;

}


// This Hanoi function needs to call another function which will work recursively;
void solve_hanoi(Hanoi& game)
{
    hanoiRecursive(game, game.getNumOfDisc(), 0, 2, 1); // First parameter is a game object;
    // Second is a total number of existing disc;
    // Remaining numbers demonstrates rod numbers of the Source, Destination & Aux Rods successively;
};



