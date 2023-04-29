/*Given a binary search tree, you have to replace each node's data with the sum of all nodes which are greater or equal than it. You need to include the current node's data also.
That is, if in given BST there is a node with data 5, you need to replace it with sum of its data (i.e. 5) and all nodes whose data is greater than or equal to 5.
Note: You don't need to return or print, just change the data of each node.*/

#include <iostream>
#include<algorithm>
#include <queue>
#include <climits>
#include<vector>
#include "BinaryTreeNode.h"
using namespace std;
void replace(BinaryTreeNode<int>* root,int* sum){
    if(root==nullptr) return;

    replace(root->right, sum);
    
    *sum = *sum + root->data;
    root->data = *sum;
    replace(root->left,sum);

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
    printTreeLevelWise(root);
    cout << "--------------------------" << endl;
    int a=0;
    int* sum=&a;
    replace(root,sum);
    printTreeLevel(root);
}