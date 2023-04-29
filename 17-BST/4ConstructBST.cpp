
//Given a sorted integer array A of size n, which contains all unique elements. You need to construct a balanced BST from this input array. Return the root of constructed BST.
// Note: If array size is even, take first mid as root.
#include<iostream>
#include <queue>
#include<climits>
#include "BinaryTreeNode.h"

#include<stack>
using namespace std;

BinaryTreeNode<int>* constructBST(vector<int>& arr,int s,int e){
    
    if(s>e) return nullptr;
    int mid = (s+e)/2;
    int data =arr[mid];
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>( data );
    root->left=constructBST(arr,s,mid-1);
    root->right=constructBST(arr,mid+1,e);
    return root;
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
    // BinaryTreeNode<int> *root = takeInputLevelWise();
    
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    BinaryTreeNode<int>* root = constructBST(arr,0,arr.size()-1);
    printTreeLevelWise(root);
    cout<<"--------------------------"<<endl;
    
    
}