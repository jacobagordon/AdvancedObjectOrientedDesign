#include <iostream>
#include "gordonj3.h"
using namespace std;


bool Queue300::isEmpty() const
{
    return(front == -1 && rear == -1);
}

bool Queue300::isFull() const
{
    return ((rear - QUEUE_SIZE)==front);
}

Queue300::Queue300():QUEUE_SIZE(3)
{
   queue = new Element300 [QUEUE_SIZE];
   front = -1;
   rear = -1;
   return;
}

Queue300::Queue300(const unsigned int v):QUEUE_SIZE(v)
{
   queue = new Element300 [QUEUE_SIZE];
   front = -1;
   rear = -1;
   return;
}

Queue300::Queue300(Queue300 &old):QUEUE_SIZE(old.QUEUE_SIZE)
{
    if (old.front == -1)
    {
        front = -1;
        rear = -1;
    }
    else
    {
//        QUEUE_SIZE = old.QUEUE_SIZE;
        front = old.front;
        rear = old.rear;
        queue = new Element300[old.QUEUE_SIZE];
        for (int i = front; i <= rear; i++)
            queue[i] = old.queue[i];
    }
}

Queue300::~Queue300()
{
    delete [] queue;
}

void Queue300::deQueue(Element300 &v)
{
   if(isEmpty())
   {
       cout<<"Queue is empty!\n";
       return;
   }
   else
   {
        v = queue[front];
        front = front+1;

        if(front == QUEUE_SIZE)
            front = 0;
    }
}

void Queue300::enQueue(const Element300 v)
{
    cout<<"Enqueuing "<< v << endl;
    if(isFull())
    {
        cout<<"The queue is full!\n";
        return;
    }
    if(isEmpty())
        front = rear = 0;

    else if(front!=0 && rear==QUEUE_SIZE)
        rear=0;

    else
        rear=rear+1;

    queue[rear]=v;
}

void Queue300::view()
{
    int ptr;

    if(isEmpty())
    {
        cout<<"Queue is empty";
        return;
    }

    cout<<"\nThe queue is\n";
    if(front<=QUEUE_SIZE && rear<=front)
    {
        for(ptr=front;ptr<QUEUE_SIZE;ptr++)
            cout<<queue[ptr]<<"\n";
        for(ptr=0;ptr<=rear;ptr++)
            cout<<queue[ptr]<<"\n";
    }
    else
        for(ptr=front;ptr<=rear;ptr++)
            cout<<queue[ptr]<<"    ";
}
