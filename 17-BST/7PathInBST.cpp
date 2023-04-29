// Given a BST and an integer k. Find and return the path from the node with data k and root (if a node with data k is present in given BST) in a list. Return empty list otherwise.
// Note: Assume that BST contains all unique elements.
#include<iostream>
#include <queue>
#include<climits>
#include "BinaryTreeNode.h"
using namespace std;

vector<int>* findPath(BinaryTreeNode<int>* root,int k){
    
    if(root==nullptr) return nullptr;
    if(root->data==k){
        vector<int>* ans=new vector<int>();
        ans->push_back(root->data);
        return ans;
    }
    else if(root->data>k){
        vector<int>* lans = findPath(root->left,k);
        if( lans!=nullptr){
            lans->push_back(root->data);
            return lans;
        }
    }else {
        vector<int>* rans = findPath(root->right,k);
        if(rans!=nullptr){
            rans->push_back(root->data);
            return rans;
        }
    }
    return nullptr;
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
    int k;
    cin>>k;
    printTreeLevelWise(root);
    cout<<"--------------------------"<<endl;
    vector<int>* ans =findPath(root,k);
    for(int i=0;i<ans->size();i++){
        cout<<ans->at(i)<<" ";
    }
    delete ans;
    delete root;
   
    
}