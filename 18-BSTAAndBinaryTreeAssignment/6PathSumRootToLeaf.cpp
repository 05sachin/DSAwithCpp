// You are given a Binary Tree of type integer, a target node, and an integer value K.
// Print the data of all nodes that have a distance K from the target node. The order in which they would be printed will not matter.
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
#include <vector>
#include "BinaryTreeNode.h"
using namespace std;
void printAtDepthK(BinaryTreeNode<int> *root, int k)
{
    if (root == nullptr||k<0)
        return;

    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    printAtDepthK(root->left, k - 1);
    printAtDepthK(root->right, k - 1);
}
int print(BinaryTreeNode<int> *root, int k, int ele)
{
    if (root == NULL)
        return -1;
    if (ele == root->data)
    {
        printAtDepthK(root, k);
        return 0;
    }
    int ld = print(root->left, k, ele);

    int rd;
    if (ld == -1)
    {
        rd = print(root->right, k, ele);
        if (rd == -1)
        {
            return -1;
        }
        else if (rd + 1 == k)
        {
            cout<<root->data << " ";
            return k;
        }
        else
        {
            printAtDepthK(root->left, k - rd - 2);
            return rd + 1;
        }
    }
    else if (ld + 1 == k)
    {
        cout<<root->data << " ";
        return k;
    }
    else
    {
        printAtDepthK(root->right, k - ld - 2);
        return ld + 1;
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
    cin >> data;
    int k;
    cin >> k;
    printTreeLevelWise(root);
    cout << "--------------------------" << endl;
    print(root, k, data);
}