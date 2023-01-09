#include <iostream>
// #include "mazoi.h"
// #include "StackQueue.h"
#include "nodes.h"



int main()
{
    Node<char>* s;

    // Maze<int> m1;
    // StackQueue<int> s1;

// m1.solve_maze();

    push_rear(s, 'c');
    printList(s);

    push_front(s, 'a');
    printList(s);

    insert(s, 'b');
    printList(s);

    push_rear(s, 'f');
    printList(s);

    push_rear(s, 'e');
    printList(s);

    push_rear(s, 'k');
    printList(s);

    pop_front(s);
    printList(s);

    pop_front(s);
    printList(s);

    pop_rear(s);
    printList(s);

    // These Functions are work with Visual Studio
    // However Due to problem of code blocks, it exits with some return number.


    return 0;
}
