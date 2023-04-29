
//Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree) or not. If yes, return true, return false otherwise.
// Duplicate elements should be in right subtree.
#include<iostream>
#include <queue>
#include<climits>
#include "BinaryTreeNode.h"

#include<stack>
using namespace std;
// 1st
int minimum(BinaryTreeNode<int>* root){
    if(root==nullptr) return INT_MAX;
    return min(root->data,min(minimum(root->left),minimum(root->right)));

}
int maximum(BinaryTreeNode<int>* root){
    if(root==nullptr) return INT_MIN;

    return max(root->data,max(maximum(root->left),maximum(root->right)));
}
bool isBST(BinaryTreeNode<int>* root){
    if(root==nullptr) return true;
    
    int leftMax = maximum(root->left);
    int rightMin=minimum(root->right);

    bool ans = (root->data>leftMax) && (root->data<=rightMin) && isBST(root->left) &&isBST(root->right);
    return ans;

}

// 2nd
class IsBSTReturn{
    public:
    bool isBST;
    int minimum;
    int maximum;
};
IsBSTReturn isBST1(BinaryTreeNode<int>* root){
    if(root==nullptr) {
        IsBSTReturn output;
        output.isBST=true;
        output.minimum=INT_MAX;
        output.maximum=INT_MIN;
        return output;

    }
    IsBSTReturn leftSub = isBST1(root->left);
    IsBSTReturn rightSub = isBST1(root->right);
    
    int minimum = min(root->data,min(leftSub.minimum,rightSub.minimum));
    int maximum = max(root->data,max(leftSub.maximum,rightSub.maximum));
    
    bool ans= (root->data > leftSub.maximum) && (root->data<=rightSub.minimum) && leftSub.isBST && rightSub.isBST;
    IsBSTReturn output;
    output.isBST=ans;
    output.minimum=minimum;
    output.maximum=maximum;
    return output;
}

// 3rd
bool isBST2(BinaryTreeNode<int>* root,int Min =INT_MIN,int Max=INT_MAX){
    if(root==nullptr) return true;
    if(root->data<=Min || root->data>=Max){
        return false;
    }
    bool lans=isBST2(root->left,Min,root->data);
    bool rans=isBST2(root->right,root->data,Max);

    return lans&&rans;
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
    cout<<"--------------------------"<<endl;
    
    
    cout<<isBST(root)<<endl;

    cout<<isBST1(root).isBST<<endl;
    cout<<isBST2(root)<<endl;
}