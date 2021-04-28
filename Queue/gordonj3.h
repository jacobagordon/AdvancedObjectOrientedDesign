/********************************************************************
*** NAME : Jacob Gordon                                           ***
*** CLASS : CSC 300                                               ***
*** ASSIGNMENT : Assignment 3                                     ***
*** DUE DATE : February 27th, 2017                                ***
*** INSTRUCTOR : HAMER                                            ***
*********************************************************************
*** DESCRIPTION : This program implements a queue                 ***
********************************************************************/
#ifndef GORDONJ3_H
#define GORDONJ3_H

#include <iostream>
using namespace std;

typedef long int Element300;

class Queue300
{
private:
    const unsigned int QUEUE_SIZE;
    Element300* queue;
    int front;
    int rear;
    bool isEmpty() const;
    bool isFull() const;
public:
    Queue300();
    Queue300(const unsigned int);
    Queue300(Queue300 &old);
    ~Queue300();
    void deQueue(Element300 &v); // removes an existing element from the front of the queue
    void enQueue(const Element300); // inserts a new element to the rear of the queue
    void view(); // shows the contents of the queue from front to rear
};
#endif
