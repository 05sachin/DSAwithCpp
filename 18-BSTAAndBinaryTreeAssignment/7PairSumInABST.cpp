/*Given a binary search tree and an integer S, find pair of nodes in the BST which sum to S. You can use extra space of the order of O(log n).
Note:
1. Assume BST contains all unique elements.
2. In a pair, print the smaller element first.*/
// You are given a Binary Tree of type integer, a target node, and an integer value K.
// Print the data of all nodes that have a distance K from the target node. The order in which they would be printed will not matter.
#include <iostream>
#include <algorithm>
#include <queue>
#include<stack>
#include <climits>
#include <vector>
#include "BinaryTreeNode.h"
using namespace std;
int totalNodes(BinaryTreeNode<int>* root){
    if(root==nullptr) return 0;
    return 1+totalNodes(root->left)+totalNodes(root->right);

}
void pairSumInABST(BinaryTreeNode<int>* root,int k){
    if(root==nullptr){
        return;
    }
    int n=totalNodes(root);
    stack<BinaryTreeNode<int>*> st;
    stack<BinaryTreeNode<int>*> rst;
    BinaryTreeNode<int>* temp=root;

    while(n>0 &&temp!=nullptr){
        st.push(temp);
        temp=temp->left;
        n--;
    }
    temp=root;
    while(n>0 &&temp!=nullptr){
        rst.push(temp);
        temp=temp->right;
        n--;
    }
    n++;

    while(!st.empty() && !rst.empty()){
        BinaryTreeNode<int>* n1=st.top();
        BinaryTreeNode<int>* n2=rst.top();
        int data = n1->data + n2->data;
        if( data==k){
            if(n1->data != n2->data)  cout<<n1->data<<" "<<n2->data<<endl;
            st.pop();
            rst.pop();
            
            
            n1=n1->right;
            while(n>=0 && n1!=nullptr){
                st.push(n1);
                n1=n1->left;
               
                n--;
                
            }
            
            n2=n2->left;
            while(n>=0 && n2!=nullptr){
                rst.push(n2);
                n2=n2->right;
                
                n--;
            }
        }else if(data<k){
            st.pop();
           
            n1=n1->right;
            while(n>=0 &&n1!=nullptr){
                st.push(n1);
                n1=n1->left;
                
                n--;
                
            }
        }else{
            rst.pop();
            
            n2=n2->left;
            while(n>=0 &&n2!=nullptr){
                rst.push(n2);
                n2=n2->right;
                
                n--;
            }
        }
    }
}
void printTreeLevel(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            BinaryTreeNode<int> *node = q.front();
            q.pop();
            cout << node->data << " ";

            if (node->left != NULL)
            {

                q.push(node->left);
            }
            if (node->right != NULL)
            {

                q.push(node->right);
            }
        }
        cout << endl;
    }
}
void printTreeLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        BinaryTreeNode<int> *node = q.front();
        q.pop();
        cout << node->data << ": ";

        if (node->left != NULL)
        {
            cout << "L" << node->left->data << ",";
            q.push(node->left);
        }
        if (node->right != NULL)
        {
            cout << "R" << node->right->data;
            q.push(node->right);
        }
        cout << endl;
    }
}
BinaryTreeNode<int> *takeInputLevelWise()
{
    int data;
    cout << "Enter root data: " << endl;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        BinaryTreeNode<int> *node = q.front();
        q.pop();

        int leftData;
        cout << "Enter left child of " << node->data << endl;
        cin >> leftData;
        if (leftData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftData);
            node->left = leftChild;
            q.push(leftChild);
        }
        int rightData;
        cout << "Enter right child of " << node->data << endl;
        cin >> rightData;

        if (rightData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightData);
            node->right = rightChild;
            q.push(rightChild);
        }
    }
    return root;
}
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    int data;
    cin>>data;
    printTreeLevelWise(root);
    cout << "--------------------------" << endl;
    pairSumInABST(root,data);
}