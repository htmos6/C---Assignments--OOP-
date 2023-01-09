#ifndef MAZOI_H
#define MAZOI_H

#include <iostream>
#include <fstream>
#include "StackQueue.h"
using namespace std;

enum Direction { N, W, S, E };

template <class T>
class Maze
{
    private:
        StackQueue<char> pathToFollow;
        int nrow, ncol; // Keep number of row and columns of the given mazoi scheme.
        char state[20][20]; // Keep state of the mazoi.
        char elementBeforeBack; // Keep element before back in order to shorten path; LBL -> F ... ETC
        int rowPosTarget, columnPosTarget; // For the second pass, keep location of the target inside integer values.
        int currentRowPos, currentColumnPos; // Keep current position of the agent in terms of row & column values.
        int initialRowPosMaster, initialColumnPosMaster; // For the second pass, keep initial location of the master inside integer values.
        enum Direction initialDirectionOfMaze; // Keep initial direction of the agent with enum values.
        enum Direction directionOfMaze; // Keep direction of the agent with enum values.

    public:
        Maze(void);
        Maze(const Maze<T>& maze);

        virtual void print_state(void) const;

        virtual bool can_move_left(void) const; // Return "true", if agent can move left.
        virtual bool can_move_right(void) const;
        virtual bool can_move_forward(void) const;
        virtual bool can_move_back(void) const;

        virtual void move_left(void); // Inside these functions call can_move_xxxxx() ... functions. If cannot move, maze state should be same.
        virtual void move_right(void);
        virtual void move_forward(void);
        virtual void move_back(void);

        virtual void solve_maze(void);

        virtual bool is_solved(void) const; // Return "true", if agent is at the target.

};


template <class T>
Maze<T>::Maze(void)
{
    ifstream input_file;
    input_file.open("C:/Users/Legion/Desktop/ASSIGNMENTS-1-2-3/ASSIGNMENT2/EE447_ASSIGNMENT2_PART2/EE447_ASSIGNMENT2_PART2/Util/include/input_maze.txt");
    input_file >> nrow >> ncol;

    for (int i = 0; i < nrow; i++)
    {
        for (int j = 0; j < ncol; j++)
        {
            input_file >> state[i][j];
            if (state[i][j] == 'N')
            {
                directionOfMaze = N;
                currentRowPos = i;
                currentColumnPos = j;

                initialRowPosMaster = i;
                initialColumnPosMaster = j;

                initialDirectionOfMaze = N;
            }
            else if (state[i][j] == 'W')
            {
                directionOfMaze = W;
                currentRowPos = i;
                currentColumnPos = j;

                initialRowPosMaster = i;
                initialColumnPosMaster = j;

                initialDirectionOfMaze = W;
            }
            else if (state[i][j] == 'S')
            {
                directionOfMaze = S;
                currentRowPos = i;
                currentColumnPos = j;

                initialRowPosMaster = i;
                initialColumnPosMaster = j;

                initialDirectionOfMaze = S;
            }
            else if (state[i][j] == 'E')
            {
                directionOfMaze = E;
                currentRowPos = i;
                currentColumnPos = j;

                initialRowPosMaster = i;
                initialColumnPosMaster = j;

                initialDirectionOfMaze = E;
            }
            else if (state[i][j] == 'T')
            {
                rowPosTarget = i;
                columnPosTarget = j;
            }
        }
    }

    input_file.close();
}


template <class T>
Maze<T>::Maze(const Maze<T>& maze) // Copy constructor for the Maze
{
    pathToFollow = maze.pathToFollow;
    nrow = maze.nrow; // Keep number of row and columns of the given mazoi scheme.
    ncol = maze.ncol;

    state[20][20] = maze.state; // Keep state of the mazoi.
    elementBeforeBack = maze.elementBeforeBack; // Keep element before back in order to shorten path; LBL -> F ... ETC

    rowPosTarget = maze.rowPosTarget; // For the second pass, keep location of the target inside integer values.
    columnPosTarget = maze.columnPosTarget; // For the second pass, keep location of the target inside integer values.

    currentRowPos = maze.currentRowPos; // Keep current position of the agent in terms of row & column values.
    currentColumnPos = maze.currentColumnPos; // Keep current position of the agent in terms of row & column values.

    initialRowPosMaster = maze.initialRowPosMaster; // For the second pass, keep initial location of the master inside integer values
    initialColumnPosMaster = maze.initialColumnPosMaster;; // For the second pass, keep initial location of the master inside integer values

    initialDirectionOfMaze = maze.initialDirectionOfMaze; // Keep initial direction of the agent with enum values.
    directionOfMaze = maze.directionOfMaze; // Keep direction of the agent with enum values.
}


template <class T>
void Maze<T>::print_state(void) const // Print the state of the current Mazoi
{

    for (int i = 0; i < nrow; ++i)
    {
        for (int j = 0; j < ncol; ++j)
        {
            cout << state[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}


template <class T>
bool Maze<T>::can_move_left(void) const
{
    switch (this->directionOfMaze)
    {
    case 0: // Direction of the master points to the N
        return (state[currentRowPos][currentColumnPos - 1] == '#') ? false : true;
        break;
    case 1: // Direction of the master points to the W
        return (state[currentRowPos + 1][currentColumnPos] == '#') ? false : true;
        break;
    case 2: // Direction of the master points to the S
        return (state[currentRowPos][currentColumnPos + 1] == '#') ? false : true;
        break;
    case 3: // Direction of the master points to the E
        return (state[currentRowPos - 1][currentColumnPos] == '#') ? false : true;
        break;
    }
}


template <class T>
bool Maze<T>::can_move_right(void) const
{
    switch (directionOfMaze)
    {
    case 0: // Direction of the master points to the N
        return (state[currentRowPos][currentColumnPos + 1] == '#') ? false : true;
        break;
    case 1: // Direction of the master points to the W
        return (state[currentRowPos - 1][currentColumnPos] == '#') ? false : true;
        break;
    case 2: // Direction of the master points to the S
        return (state[currentRowPos][currentColumnPos - 1] == '#') ? false : true;
        break;
    case 3: // Direction of the master points to the E
        return (state[currentRowPos + 1][currentColumnPos] == '#') ? false : true;
        break;
    }
}


template <class T>
bool Maze<T>::can_move_forward(void) const
{
    switch (this->directionOfMaze)
    {
    case 0: // Direction of the master points to the N
        return (state[currentRowPos - 1][currentColumnPos] == '#') ? false : true;
        break;
    case 1: // Direction of the master points to the W
        return (state[currentRowPos][currentColumnPos - 1] == '#') ? false : true;
        break;
    case 2: // Direction of the master points to the S
        return (state[currentRowPos + 1][currentColumnPos] == '#') ? false : true;
        break;
    case 3: // Direction of the master points to the E
        return (state[currentRowPos][currentColumnPos + 1] == '#') ? false : true;
        break;
    }
}


template <class T>
bool Maze<T>::can_move_back(void) const
{
    switch (this->directionOfMaze)
    {
    case 0: // Direction of the master points to the N
        return (state[currentRowPos + 1][currentColumnPos] == '#') ? false : true;
        break;
    case 1: // Direction of the master points to the W
        return (state[currentRowPos][currentColumnPos + 1] == '#') ? false : true;
        break;
    case 2: // Direction of the master points to the S
        return (state[currentRowPos - 1][currentColumnPos] == '#') ? false : true;
        break;
    case 3: // Direction of the master points to the E
        return (state[currentRowPos][currentColumnPos - 1] == '#') ? false : true;
        break;
    }
}


template <class T>
void Maze<T>::move_left(void)
{
    if (this->can_move_left())
    {
        switch (this->directionOfMaze)
        {
        case 0: // Direction of the master points to the N
            directionOfMaze = W;
            state[currentRowPos][currentColumnPos] = '.';
            currentColumnPos -= 1;
            state[currentRowPos][currentColumnPos] = 'W';
            break;
        case 1: // Direction of the master points to the W
            directionOfMaze = S;
            state[currentRowPos][currentColumnPos] = '.';
            currentRowPos += 1;
            state[currentRowPos][currentColumnPos] = 'S';
            break;
        case 2: // Direction of the master points to the S
            directionOfMaze = E;
            state[currentRowPos][currentColumnPos] = '.';
            currentColumnPos += 1;
            state[currentRowPos][currentColumnPos] = 'E';
            break;
        case 3: // Direction of the master points to the E
            directionOfMaze = N;
            state[currentRowPos][currentColumnPos] = '.';
            currentRowPos -= 1;
            state[currentRowPos][currentColumnPos] = 'N';
            break;
        }
    }
}


template <class T>
void Maze<T>::move_right(void)
{
    if (this->can_move_right())
    {
        switch (this->directionOfMaze)
        {
        case 0: // Direction of the master points to the N
            directionOfMaze = E;
            state[currentRowPos][currentColumnPos] = '.';
            currentColumnPos += 1;
            state[currentRowPos][currentColumnPos] = 'E';
            break;
        case 1: // Direction of the master points to the W
            directionOfMaze = N;
            state[currentRowPos][currentColumnPos] = '.';
            currentRowPos -= 1;
            state[currentRowPos][currentColumnPos] = 'N';
            break;
        case 2: // Direction of the master points to the S
            directionOfMaze = W;
            state[currentRowPos][currentColumnPos] = '.';
            currentColumnPos -= 1;
            state[currentRowPos][currentColumnPos] = 'W';
            break;
        case 3: // Direction of the master points to the E
            directionOfMaze = S;
            state[currentRowPos][currentColumnPos] = '.';
            currentRowPos += 1;
            state[currentRowPos][currentColumnPos] = 'S';
            break;
        }
    }
}


template <class T>
void Maze<T>::move_forward(void)
{
    if (this->can_move_forward())
    {
        switch (this->directionOfMaze)
        {
        case 0: // Direction of the master points to the N
            directionOfMaze = N;
            state[currentRowPos][currentColumnPos] = '.';
            currentRowPos -= 1;
            state[currentRowPos][currentColumnPos] = 'N';
            break;
        case 1: // Direction of the master points to the W
            directionOfMaze = W;
            state[currentRowPos][currentColumnPos] = '.';
            currentColumnPos -= 1;
            state[currentRowPos][currentColumnPos] = 'W';
            break;
        case 2: // Direction of the master points to the S
            directionOfMaze = S;
            state[currentRowPos][currentColumnPos] = '.';
            currentRowPos += 1;
            state[currentRowPos][currentColumnPos] = 'S';
            break;
        case 3: // Direction of the master points to the E
            directionOfMaze = E;
            state[currentRowPos][currentColumnPos] = '.';
            currentColumnPos += 1;
            state[currentRowPos][currentColumnPos] = 'E';
            break;
        }
    }
}


template <class T>
void Maze<T>::move_back(void)
{
    if (this->can_move_back())
    {
        switch (this->directionOfMaze)
        {
        case 0: // Direction of the master points to the N
            directionOfMaze = S;
            state[currentRowPos][currentColumnPos] = '.';
            currentRowPos += 1;
            state[currentRowPos][currentColumnPos] = 'S';
            break;
        case 1: // Direction of the master points to the W
            directionOfMaze = E;
            state[currentRowPos][currentColumnPos] = '.';
            currentColumnPos += 1;
            state[currentRowPos][currentColumnPos] = 'E';
            break;
        case 2: // Direction of the master points to the S
            directionOfMaze = N;
            state[currentRowPos][currentColumnPos] = '.';
            currentRowPos -= 1;
            state[currentRowPos][currentColumnPos] = 'N';
            break;
        case 3: // Direction of the master points to the E
            directionOfMaze = W;
            state[currentRowPos][currentColumnPos] = '.';
            currentColumnPos -= 1;
            state[currentRowPos][currentColumnPos] = 'W';
            break;
        }
    }
}


template <class T>
void Maze<T>::solve_maze(void)
{
    cout << "First pass: \n";
    pathToFollow.print_elements();
    this->print_state();

    while (this->is_solved() == 0) // Loop until is solved returns TRUE
    {
        if (this->can_move_left())
        {
            this->move_left();
            if (pathToFollow.size() == 0 || pathToFollow.peek_rear() != 'B')
            {
                pathToFollow.push_rear('L');
            }
            else if (pathToFollow.size() == 1 && pathToFollow.peek_front() == 'B') // If first command is Back, do not pop it. Because you won't be able to solve Mazoi problem.
            {
                pathToFollow.push_rear('L');
            }
            else
            {
                pathToFollow.pop_rear(); // POP Back Command
                elementBeforeBack = pathToFollow.pop_rear();
                switch (elementBeforeBack)
                {
                case 'L': //CASE : LBL --> F
                    pathToFollow.push_rear('F');
                    break;
                case 'F': //CASE : FBL --> R
                    pathToFollow.push_rear('R');
                    break;
                case 'R': //CASE : RBL --> B
                    pathToFollow.push_rear('B');
                    break;
                case 'B': //CASE : BBL --> L
                    pathToFollow.push_rear('L');
                    break;
                }
            }
        }

        else if (this->can_move_forward())
        {
            this->move_forward();
            if (pathToFollow.size() == 0 || pathToFollow.peek_rear() != 'B')
            {
                pathToFollow.push_rear('F');
            }
            else if (pathToFollow.size() == 1 && pathToFollow.peek_front() == 'B') // If first command is Back, do not pop it. Because you won't be able to solve Mazoi problem.
            {
                pathToFollow.push_rear('F');
            }
            else
            {
                pathToFollow.pop_rear(); // POP Back Command
                elementBeforeBack = pathToFollow.pop_rear();
                switch (elementBeforeBack)
                {
                case 'L': //CASE : LBF --> R
                    pathToFollow.push_rear('R');
                    break;
                case 'F': //CASE : FBF --> B
                    pathToFollow.push_rear('B');
                    break;
                case 'R': //CASE : RBF --> L
                    pathToFollow.push_rear('L');
                    break;
                case 'B': //CASE : BBF --> F
                    pathToFollow.push_rear('F');
                    break;
                }
            }
        }



        else if (this->can_move_right())
        {
            this->move_right();
            if (pathToFollow.size() == 0 || pathToFollow.peek_rear() != 'B')
            {
                pathToFollow.push_rear('R');
            }
            else if (pathToFollow.size() == 1 && pathToFollow.peek_front() == 'B') // If first command is Back, do not pop it. Because you won't be able to solve Mazoi problem.
            {
                pathToFollow.push_rear('R');
            }
            else
            {
                pathToFollow.pop_rear(); // POP Back Command
                elementBeforeBack = pathToFollow.pop_rear();
                switch (elementBeforeBack)
                {
                case 'L': //CASE : LBR --> B
                    pathToFollow.push_rear('B');
                    break;
                case 'F': //CASE : FBR --> L
                    pathToFollow.push_rear('L');
                    break;
                case 'R': //CASE : RBR --> F
                    pathToFollow.push_rear('F');
                    break;
                case 'B': //CASE : BBR --> R
                    pathToFollow.push_rear('R');
                    break;
                }
            }

        }

        else if (this->can_move_back())
        {
            this->move_back();
            if (pathToFollow.size() == 0 || pathToFollow.peek_rear() != 'B')
            {
                pathToFollow.push_rear('B');
            }
            else if (pathToFollow.size() == 1 && pathToFollow.peek_front() == 'B') // If first command is Back, do not pop it. Because you won't be able to solve Mazoi problem.
            {
                pathToFollow.push_rear('B');
            }
            else
            {
                pathToFollow.pop_rear(); // POP Back Command
                elementBeforeBack = pathToFollow.pop_rear();
                switch (elementBeforeBack)
                {
                case 'L': //CASE : LBB --> L
                    pathToFollow.push_rear('L');
                    break;
                case 'F': //CASE : FBB --> F
                    pathToFollow.push_rear('F');
                    break;
                case 'R': //CASE : RBB --> R
                    pathToFollow.push_rear('R');
                    break;
                case 'B': //CASE : BBB --> B
                    pathToFollow.push_rear('B');
                    break;
                }
            }
        }
        pathToFollow.print_elements();
        this->print_state();
    }
    cout << "Maze is solved.\n\n";

    // Return back to conditions at the beginning of the First Pass
    currentRowPos = initialRowPosMaster;
    currentColumnPos = initialColumnPosMaster;
    state[rowPosTarget][columnPosTarget] = 'T';

    if (initialDirectionOfMaze == 0) // N
    {
        state[currentRowPos][currentColumnPos] = 'N';
        directionOfMaze = N;
    }
    else if (initialDirectionOfMaze == 1) // W
    {
        state[currentRowPos][currentColumnPos] = 'W';
        directionOfMaze = W;
    }
    else if (initialDirectionOfMaze == 2) // S
    {
        state[currentRowPos][currentColumnPos] = 'S';
        directionOfMaze = S;
    }
    else if (initialDirectionOfMaze == 3) // E
    {
        state[currentRowPos][currentColumnPos] = 'E';
        directionOfMaze = E;
    }

    cout << "Second pass: \n";
    pathToFollow.print_elements();
    this->print_state();

    while (this->is_solved() == 0) // Print shortest solution of the Mazoi
    {
        switch (pathToFollow.peek_front())
        {
        case 'L':
            this->move_left();
            pathToFollow.pop_front();
            break;
        case 'F':
            this->move_forward();
            pathToFollow.pop_front();
            break;
        case 'R':
            this->move_right();
            pathToFollow.pop_front();
            break;
        case 'B':
            this->move_back();
            pathToFollow.pop_front();
            break;
        }
        pathToFollow.print_elements();
        this->print_state();
    }
}


template <class T>
bool Maze<T>::is_solved(void) const
{
    return (currentRowPos == rowPosTarget && currentColumnPos == columnPosTarget) ? true : false;
}


#endif
