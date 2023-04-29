
// Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.
#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
#include "Node.cpp"

using namespace std;

vector<Node<int>*> levelLL(BinaryTreeNode<int>* root){
    vector< Node<int>* > ans;
    if(root==NULL ) return ans;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        int n=q.size();
        Node<int>* head=NULL;
        Node<int>* tail=NULL;
        for(int i=0;i<n;i++){
            BinaryTreeNode<int>* node = q.front();
            q.pop();
            Node<int>* newNode= new Node<int>(node->data);
            if(head==NULL){
                head=newNode;
                tail=newNode;
            }else{
                tail->next=newNode;
                tail=tail->next;
            }

            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }

        }
        if(head!=NULL){
            ans.push_back(head);
        }
    }
    return ans;

}

/*
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
}*/

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
    cout<<"---------------"<<endl;

    vector<Node<int>*> ans = levelLL(root);
    for(int i=0;i<ans.size();i++){
        Node<int>* head = ans[i];
        while(head!=NULL){
            cout<<head->data<<" ";
            head=head->next;
        }
        cout<<endl;

    }
    
}