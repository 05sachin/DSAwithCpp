/*Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree. You have to return the height of largest BST.*/
#include <iostream>
#include<algorithm>
#include <queue>
#include <climits>
#include<vector>
#include "BinaryTreeNode.h"
using namespace std;
bool isBST(BinaryTreeNode<int>* root,int Min =INT_MIN,int Max=INT_MAX){
    if(root==nullptr) return true;
    if(root->data<Min || root->data>Max){
        return false;
    }
    bool lans=isBST(root->left,Min,root->data-1);
    bool rans=isBST(root->right,root->data,Max);

    return lans&&rans;
}
int height(BinaryTreeNode<int>* root){
    if(root==NULL) return 0;
    return 1+max(height(root->left),height(root->right));
}
int largestBST(BinaryTreeNode<int>* root){
    if(root==NULL) return 0;
    if(isBST(root)){
        return height(root);
    }else{
        int lans = largestBST(root->left);
        int rans = largestBST(root->right);
        return max(lans,rans);

    }
}
class Check{
    public:
    int minimum;
    int maximum;
    bool isBST;
    int height;
    Check(){
        minimum=INT_MAX;
        maximum=INT_MIN;
        isBST=true;
        height=0;
    }

};
Check* largestBST1(BinaryTreeNode<int>* root){
    if(root==nullptr){
        return new Check();
    }
    Check* leftAns= largestBST1(root->left);
    Check* rightAns = largestBST1(root->right);

    int minimum=min(root->data,min(leftAns->minimum,rightAns->minimum));
    int maximum=max(root->data,max(leftAns->maximum,rightAns->maximum));
    bool isBST= (root->data > leftAns->maximum) && (rightAns->minimum >= root->data) &&  leftAns->isBST && rightAns->isBST;
    int height = max(leftAns->height,rightAns->height);
    if(isBST){
        height++;
    }
    
    Check* ans = new Check();
    ans->minimum = minimum;
    ans->maximum= maximum;
    ans->isBST= isBST;
    ans->height=height;
    return ans;
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
    cout<<largestBST1(root)->height<<endl;
}