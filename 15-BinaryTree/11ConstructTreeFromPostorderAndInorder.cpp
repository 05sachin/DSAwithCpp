// For a given postorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.
#include <iostream>
#include <queue>
#include<vector>
#include "BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int>* construct(vector<int>& post,vector<int>& in,int ps,int pe,int is,int ie){
    if(ps>pe || is>ie) return NULL;
    
    int rootData = post[pe];
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    for(int i=is;i<=ie;i++){
        if(rootData==in[i]){
            int j = ps-is+i-1;
            root->left = construct(post,in,ps,j,is,i-1);
            root->right = construct(post,in,j+1,pe-1,i+1,ie);
        }
    }
    return root;
}

void print(BinaryTreeNode<int> *root)
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
            cout << node->data <<" ";
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
void printLevelWise(BinaryTreeNode<int> *root)
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
            cout << "L " << node->left->data << ",";
            q.push(node->left);
        }
        if (node->right != NULL)
        {
            cout << "R " << node->right->data;
            q.push(node->right);
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> in(n);
    vector<int> pre(n);
    for(int i=0;i<n;i++){
        cin>>pre[i];
    }
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    BinaryTreeNode<int>* root = construct(pre,in,0,n-1,0,n-1);
    print(root);
    printLevelWise(root);
   
     
    delete root;
    return 0;
}