
// Given a binary tree, print the zig zag order i.e print level 1 from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.
#include <queue>
#include "BinaryTreeNode.h"
#include "Node.cpp"
#include<stack>
using namespace std;
void zig(BinaryTreeNode<int>* root){
    if(root==NULL) return;
    stack<BinaryTreeNode<int>*> s1; // r to l
    stack<BinaryTreeNode<int>*> s2; // l to r
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        
        if(!s1.empty()){
            int n = s1.size();
            for(int i=0;i<n;i++){
                BinaryTreeNode<int>* node=s1.top();
                s1.pop();
                cout<<node->data<<" ";
                if(node->left!=NULL) s2.push(node->left);
                if(node->right!=NULL) s2.push(node->right);

            }
            cout<<endl;
        }
        else{
            int n=s2.size();
            for(int i=0;i<n;i++){
                BinaryTreeNode<int>* node = s2.top();
                s2.pop();
                cout<<node->data<<" ";
                if(node->right!=NULL) s1.push(node->right);
                if(node->left!=NULL) s1.push(node->left);
            }
            cout<<endl;
        }
    }
}
void ZigZagTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    int k = 1;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            BinaryTreeNode<int> *node = q.front();
            q.pop();
            ans.push_back(node->data);
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }
        if(k%2!=0){
            for(int i=0;i<ans.size();i++){
                cout<<ans[i]<<" ";
            }
        }else{
            for(int i=ans.size()-1;i>=0;i--){
                cout<<ans[i]<<" ";
            }
        }
        k++;
        cout<<endl;
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
    cout<<"--------------------------"<<endl;
    ZigZagTree(root);
    cout<<"-----------------------------"<<endl;
    zig(root);
}