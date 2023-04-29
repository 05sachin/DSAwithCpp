/*Given a binary tree and two nodes, find LCA (Lowest Common Ancestor) of the given two nodes in Binary Tree. Read about LCA if you are having doubts about the definition.
If out of 2 nodes only one node is present, return that node.
If both are not present, return -1.*/

#include <iostream>
#include<algorithm>
#include <queue>
#include <climits>
#include<vector>
#include "BinaryTreeNode.h"
using namespace std;
int LCA(BinaryTreeNode<int>* root,int n1,int n2){
    if(root==nullptr) return -1;
    if(root->data==n1 || root->data==n2){
        return root->data;
    }
    int lans=LCA(root->left,n1,n2);
    int rans = LCA(root->right,n1,n2);
    if(lans!=-1&&rans!=-1){
        return root->data;
    }else if(lans!=-1){
        return lans;
    }else if(rans!=-1){
        return rans;
    }else{
        return -1;
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
    int x,y;
    cin>>x;
    cin>>y;
    printTreeLevelWise(root);
    cout << "--------------------------" << endl;
    cout<<LCA(root,x,y)<<endl;
}