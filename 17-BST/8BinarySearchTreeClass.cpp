/*Problem Description:
Implement the BST class which includes following functions -
1. search
Given an element, find if that is present in BST or not. Return true or false.
2. insert -
Given an element, insert that element in the BST at the correct position. Assume unique elements will be given.
3. delete -
Given an element, remove that element from the BST. If the element which is to be deleted has both children, replace that with the minimum element from right sub-tree.
4. printTree (recursive) -*/
#include<iostream>
#include "BST.h"
using namespace std;

int main()
{
    BST b;
    
    b.insert(10);
    cout<<"--------------------------"<<endl;

    b.insert(5);
    b.insert(20);
    b.insert(7);
    b.insert(3);
    b.insert(15);
    b.printTree();
    b.deleteData(10);
    b.deleteData(10);
    
    b.printTree();
    
      
}