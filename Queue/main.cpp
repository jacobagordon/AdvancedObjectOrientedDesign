#include <iostream>
#include "gordonj3.h"
using namespace std;

int main()
{
    Queue300 test(6);
    Element300 v;

    test.enQueue(12);
    test.enQueue(13);
    test.enQueue(14);
    test.enQueue(15);
    test.enQueue(16);
    test.enQueue(17);
    Queue300 test1(test);
    test.deQueue(v);
    cout<<"Dequeued value is "<<v<<endl;
    test.deQueue(v);
    cout<<"Dequeued value is "<<v<<endl;
    test.view();
    test1.view();
}
