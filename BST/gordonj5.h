/********************************************************************
*** NAME : Jacob Gordon                                           ***
*** CLASS : CSC 300                                               ***
*** ASSIGNMENT : Assignment 5                                     ***
*** DUE DATE : March 27th, 2017                                   ***
*** INSTRUCTOR : HAMER                                            ***
*********************************************************************
*** DESCRIPTION : This program implements a BST                   ***
********************************************************************/
#ifndef GORDONJ5_H
#define GORDONJ5_H

#include <iostream>
using namespace std;

typedef double Element300;
struct TNode300;
typedef TNode300 * TNode300Ptr;
struct TNode300
{
    Element300 element;
    Element300 count;
    TNode300Ptr left;
    TNode300Ptr right;
};

class BST300
{
public:

    TNode300Ptr tree;
    BST300();
    BST300(const BST300 &);
    ~BST300();
    void insert(const Element300);
    void remove(const Element300);
    TNode300Ptr find(const Element300) const;
    void preOrder() const;
    void inOrder() const;
    void postOrder() const;
private:
    void insert(const Element300, TNode300Ptr &);
    void remove(const Element300, TNode300Ptr &);
    TNode300Ptr find(const Element300, const TNode300Ptr) const;
    void preOrder(const TNode300Ptr) const;
    void inOrder(const TNode300Ptr) const;
    void postOrder(const TNode300Ptr) const;
    void copy(const TNode300Ptr);
    void destroy(TNode300Ptr &);
    void removeNode(TNode300Ptr &);
    void findMinNode(TNode300Ptr &, TNode300Ptr &);

};
#endif

