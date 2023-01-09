#ifndef STACKQUEUE_H
#define STACKQUEUE_H

#include <iostream>
using namespace std;

const int SIZE = 1024;

template <class T>
class StackQueue
{
private:
    int front, rear, counter;
    T StackQueueList[SIZE];

public:
    StackQueue();
    virtual void push_front(const T& item);
    virtual void push_rear(const T& item);

    virtual T pop_front(void);
    virtual T pop_rear(void);
    virtual T peek_front(void) const;
    virtual T peek_rear(void) const;
    virtual int size(void) const;

    virtual void print_elements(void) const; // Print elements from rear to front.
};


template <class T>
StackQueue<T>::StackQueue()
{
    front = 0;
    rear = 0;
    counter = 0;
}


template <class T>
void StackQueue<T>::push_front(const T& item)
{
    if (counter == 0)
    {
        StackQueueList[front] = item;
        rear += 1;
        counter += 1;
    }
    else
    {
        for (int i = rear - 1; i >= front; i--)
        {
            StackQueueList[i + 1] = StackQueueList[i];
        }

        StackQueueList[front] = item;
        rear += 1;
        counter += 1;
    }
}


template <class T>
void StackQueue<T>::push_rear(const T& item)
{
    if (counter == SIZE)
    {
        cerr << "StackQueue is Full !" << endl;
    }
    else
    {
        counter += 1;
        StackQueueList[rear] = item;
        rear += 1;
    }
}


template <class T>
T StackQueue<T>::pop_front(void)
{
    if (counter == 0)
    {
        cerr << "Empty StackQueue! 0" << endl;
    }
    else
    {
        T temp = StackQueueList[front];
        counter -= 1;
        front += 1;
        return temp;
    }
}


template <class T>
T StackQueue<T>::pop_rear(void)
{
    if (counter == 0)
    {
        cerr << "Empty StackQueue! 1" << endl;
    }
    else
    {
        counter -= 1;
        rear -= 1;
        T temp = StackQueueList[rear];
        return temp;
    }
}


template <class T>
T StackQueue<T>::peek_front(void) const
{
    if (counter == 0)
    {
        cerr << "Empty StackQueue! 2" << endl;
    }
    else if (counter >= 1 && counter <= SIZE)
    {
        return StackQueueList[front];
    }
}


template <class T>
T StackQueue<T>::peek_rear(void) const
{
    if (counter == 0)
    {
        cerr << "Empty StackQueue! 3" << endl;
    }
    else if (counter >= 1 && counter <= SIZE)
    {
        return StackQueueList[rear - 1];
    }
}


template <class T>
void StackQueue<T>::print_elements(void) const
{
    cout << "SQ: ";
    for (int i = front; i <= rear - 1; i++)
    {
        cout << StackQueueList[i] << "";
    }
    cout << endl;
}


template <class T>
int StackQueue<T>::size(void) const
{
    return counter;
}

#endif
