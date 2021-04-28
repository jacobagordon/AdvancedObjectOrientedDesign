#include <iostream>
#include "gordonj5.h"
using namespace std;
/********************************************************************
*** FUNCTION constructor                                          ***
*********************************************************************
*** DESCRIPTION : This function creates an empty tree             ***
*** INPUT ARGS : NONE                                             ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN : void                                                 ***
********************************************************************/
BST300::BST300() {
    tree = nullptr;
}
/********************************************************************
*** FUNCTION copy constructor                                     ***
*********************************************************************
*** DESCRIPTION : This function creates a copy of an existing tree***
*** INPUT ARGS : BST300 &                                         ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN : void                                                 ***
********************************************************************/
BST300::BST300(const BST300 &old){
    tree = NULL;
    copy(old.tree);
}
/********************************************************************
*** FUNCTION copy                                                 ***
*********************************************************************
*** DESCRIPTION : Used in copy constructor                        ***
*** INPUT ARGS : TNode300Ptr                                      ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN : void                                                 ***
********************************************************************/
void BST300::copy(const TNode300Ptr n){

    if(n){
        for(int i = 0; i < n->count; i++)
            insert(n->element);
        copy(n->left);
        copy(n->right);
    }
}
/********************************************************************
*** FUNCTION insert                                               ***
*********************************************************************
*** DESCRIPTION : calls insert function                           ***
*** INPUT ARGS : Element300                                       ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN : void                                                 ***
********************************************************************/
void BST300::insert(const Element300 elem) {
    return(insert(elem, tree));
}
/********************************************************************
*** FUNCTION insert                                               ***
*********************************************************************
*** DESCRIPTION : Adds a node to the tree                         ***
*** INPUT ARGS : Element300, TNode300Ptr                          ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN : void                                                 ***
********************************************************************/
void BST300::insert(const Element300 elem, TNode300Ptr &root) {
	if(root == NULL) { // empty tree
		TNode300Ptr newTNode300 = new (nothrow) TNode300;
		root = newTNode300;
		newTNode300->count = 1;
        newTNode300->element = elem;
        newTNode300->left = newTNode300->right = nullptr;
	}
	// if data to be inserted is lesser, insert in left subtree.
	else if(root->element < elem){
        insert(elem, root->right);
    }
    else if(root->element > elem){
        insert(elem, root->left);
    }
    else if(root->element == elem){
        root->count++;
    }
}
/********************************************************************
*** FUNCTION find                                                 ***
*********************************************************************
*** DESCRIPTION : calls the find function                         ***
*** INPUT ARGS : element300                                       ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN : TNode300Ptr                                          ***
********************************************************************/
TNode300Ptr BST300::find(const Element300 elem) const{
   return find(elem, tree);
}
/********************************************************************
*** FUNCTION find                                                 ***
*********************************************************************
*** DESCRIPTION : Traverses the tree and find a value             ***
*** INPUT ARGS : Element300, TNode300Ptr                          ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN : TNode300Ptr                                          ***
********************************************************************/
TNode300Ptr BST300::find(const Element300 elem, const TNode300Ptr root) const{
    if(root == nullptr){
        return root;
    }
    else if(root->element == elem){

        return root;
    }
    else if(elem <= root->element){
        return find(elem, root->left);
    }
    else {
        return find(elem, root->right);
    }
}
/********************************************************************
*** FUNCTION inOrder                                              ***
*********************************************************************
*** DESCRIPTION : This function calls inOrder                     ***
*** INPUT ARGS : NONE                                             ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN : void                                                 ***
********************************************************************/
void BST300::inOrder() const{
    cout << "InOrder: ";
    cout << "START -> ";
    inOrder(tree);
    cout << "STOP.\n";
}
/********************************************************************
*** FUNCTION inOrder                                              ***
*********************************************************************
*** DESCRIPTION : This function displays the tree in order        ***
*** INPUT ARGS : TNode300Ptr                                      ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN : void                                                 ***
********************************************************************/
void BST300::inOrder(const TNode300Ptr root) const{
    if (root)
    {
        inOrder( root->left );
        cout << root->element << "/" << root->count << " -> ";
        inOrder( root->right );
    }
}
/********************************************************************
*** FUNCTION postOrder                                            ***
*********************************************************************
*** DESCRIPTION : This function calls postOrder function          ***
*** INPUT ARGS : NONE                                             ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN : void                                                 ***
********************************************************************/
void BST300::postOrder() const{
    cout << "PostOrder: ";
    cout << "START -> ";
    postOrder(tree);
    cout << "STOP.\n";
}
/********************************************************************
*** FUNCTION postOrder                                            ***
*********************************************************************
*** DESCRIPTION : This function displays the tree in post order   ***
*** INPUT ARGS : TNode300Ptr                                      ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN : void                                                 ***
********************************************************************/
void BST300::postOrder(const TNode300Ptr root) const{
    if (root)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->element << "/" << root->count << " -> ";
    }
}
/********************************************************************
*** FUNCTION preOrder                                             ***
*********************************************************************
*** DESCRIPTION : This function calls the preOrder function       ***
*** INPUT ARGS : NONE                                             ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN : void                                                 ***
********************************************************************/
void BST300::preOrder() const{
    cout << "PreOrder: ";
    cout << "START -> ";
    preOrder(tree);
    cout << "STOP.\n";
}
/********************************************************************
*** FUNCTION preOrder                                             ***
*********************************************************************
*** DESCRIPTION : This function displays the tree in pre order    ***
*** INPUT ARGS : TNode300Ptr                                      ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN : void                                                 ***
********************************************************************/
void BST300::preOrder(const TNode300Ptr root) const{
    if(root)
    {
        cout << root->element << "/" << root->count << " -> ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
/********************************************************************
*** FUNCTION destroy                                              ***
*********************************************************************
*** DESCRIPTION : This function is used in the destructor         ***
*** INPUT ARGS : TNode300Ptr &                                    ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN : void                                                 ***
********************************************************************/
void BST300::destroy(TNode300Ptr &root){
    if (root){
        destroy(root->left);
        destroy(root->right);
        delete root;
    }
}
/********************************************************************
*** FUNCTION destructor                                           ***
*********************************************************************
*** DESCRIPTION : This function destroys a tree                   ***
*** INPUT ARGS : NONE                                             ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN : void                                                 ***
********************************************************************/
BST300::~BST300() {
    destroy(tree);
}
/********************************************************************
*** FUNCTION findMinNode                                          ***
*********************************************************************
*** DESCRIPTION : This function finds the smallest node           ***
*** INPUT ARGS : TNode300Ptr &, TNode300Ptr &                     ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN : void                                                 ***
********************************************************************/
void BST300::findMinNode( TNode300Ptr &Node, TNode300Ptr &holder ){

    if(Node->left == NULL){
        holder = Node;
        return;
    }
    else{
        findMinNode(Node->left,holder);
    }

}
/********************************************************************
*** FUNCTION remove                                               ***
*********************************************************************
*** DESCRIPTION : This function calls remove                      ***
*** INPUT ARGS : Element300                                       ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN : void                                                 ***
********************************************************************/
void BST300::remove(const Element300 num){
    remove(num, tree);
}
/********************************************************************
*** FUNCTION remove                                               ***
*********************************************************************
*** DESCRIPTION : This function finds node to be removed          ***
*** INPUT ARGS : Element300, TNode300Ptr                          ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN : void                                                 ***
********************************************************************/
void BST300::remove(const Element300 elem, TNode300Ptr &root){
    if(root == nullptr){
        cout<< "Element does not exist in tree."<<endl;
        return;
    }
    else if(elem > root->element){
        remove(elem, root->right);
    }
    else if(elem < root->element){
        remove(elem, root->left);
    }
    else if(elem == root->element){
        removeNode(root);
    }
}
/********************************************************************
*** FUNCTION remove                                               ***
*********************************************************************
*** DESCRIPTION : This function finds node                        ***
*** INPUT ARGS : TNode300Ptr                                      ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                            ***
*** RETURN : void                                                 ***
********************************************************************/
void BST300::removeNode(TNode300Ptr &root){
    if(root->count != 1){
        root->count--;
    }
    else{
        TNode300Ptr temp;
        if(root->left == nullptr && root->right == nullptr){
            temp = root;
            root = nullptr;
            delete temp;
            temp = nullptr;
        }
        else if(root->left == nullptr && root->right != nullptr){
            temp = root;
            root = root->right;
            delete temp;
            temp = nullptr;
        }
        else if(root->left !=nullptr && root->right == nullptr){
            temp = root;
            root = root->left;
            delete temp;
            temp = nullptr;
        }
        else{
            findMinNode(root->right, temp);
            root->element = temp->element;
            root->count = temp->count;
            remove(temp->element, root->right);
        }
    }
}


