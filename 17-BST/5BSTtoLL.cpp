
//Given a BST, convert it into a sorted linked list. You have to return the head of LL.
#include<iostream>
#include <queue>
#include<climits>
#include "BinaryTreeNode.h"
#include "Node.h"

#include<stack>
using namespace std;

pair<Node<int>*,Node<int>*>  BSTtoLL(BinaryTreeNode<int>* root){
    if(root==nullptr) return {nullptr,nullptr};
    Node<int>* head=nullptr;
    Node<int>* tail=nullptr;
    
    pair<Node<int>*,Node<int>*> pleft=BSTtoLL(root->left);
    if(pleft.first!=nullptr)
        head=pleft.first;
    
    Node<int>* node = new Node<int>(root->data);
    if(head!=nullptr) pleft.second->next = node;
    else{
        head=node;
    }

    pair<Node<int>*,Node<int>*> pright = BSTtoLL(root->right);
    node->next=pright.first;
    if(pright.first!=nullptr) tail=pright.second;
    else tail=node;
    return {head,tail};

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
    Node<int>* node = BSTtoLL(root).first;
    while(node!=nullptr){
    cout<<node->data<<" ";
    node=node->next;
    }
    
}