/********************************************************************
*** NAME : Jacob Gordon                                           ***
*** CLASS : CSC 300                                               ***
*** ASSIGNMENT : Assignment 6                                     ***
*** DUE DATE : April 9th, 2017                                ***
*** INSTRUCTOR : HAMER                                            ***
*********************************************************************
*** DESCRIPTION : This program counts the amount of pascal reserved words in a file                 ***
********************************************************************/
#ifndef GORDONJ6H_H
#define GORDONJ6H_H

#include <iostream>
using namespace std;

const unsigned LINE_SIZE = 80;
typedef char Element300 [LINE_SIZE + 1];

class Hash300{
    public:
        Hash300(); //constructor
        ~Hash300(); //destructor
        void find(const Element300); //finds an element300 on the hash table
        void view() const;  //shows the count and addresses of the values on the hash table
    private:
        enum TableLimit {TABLE_SIZE = 38};
        struct TableNode300 {
            Element300 element;
            unsigned count;
        };
        TableNode300 hashTable[TABLE_SIZE];
        unsigned hashElement(const Element300) const;   //adds an element to the hash array
        unsigned convertChar(const char) const; //convert a char to a number value
        void create();  //initialize hash table to empty
        void fill();    //insert Pascal reserved words PRWORDS.DAT
};
#endif
