#include "BinaryTreeNode.h"
#include <iostream>
#include <queue>
using namespace std;
class BST
{
    BinaryTreeNode<int> *root;

public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }

private:
    void printTree(BinaryTreeNode<int> *node)
    {
        if (node == NULL)
            return;
        cout << node->data << ":";
        if (node->left != NULL)
        {
            cout << "L" << node->left->data << ",";
        }
        if (node->right != NULL)
        {
            cout << "R" << node->right->data;
        }
        cout << endl;
        printTree(node->left);
        printTree(node->right);
    }

public:
    void printTree()
    {
        printTree(root);
        return;
    }

private:
    BinaryTreeNode<int> *deleteData(BinaryTreeNode<int> *node, int data)
    {
        if (node == nullptr)
            return nullptr;
        if (node->data > data)
        {
            node->left = deleteData(node->left, data);
        }
        else if (node->data < data)
        {
            node->right = deleteData(node->right, data);
        }
        else
        {
            if (node->left == nullptr && node->right == nullptr)
            {
                delete node;
                return nullptr;
            }
            else if (node->left == nullptr)
            {
                BinaryTreeNode<int> *temp = node->right;
                node->right = nullptr;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                BinaryTreeNode<int> *temp = node->left;
                node->left = nullptr;
                delete node;
                return temp;
            }
            else
            {
                BinaryTreeNode<int> *minNode = node->right;
                while (minNode->left != nullptr)
                {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = deleteData(node->right, rightMin);
            }
        }
        return node;
    }

public:
    void deleteData(int data)
    {
        this->root = deleteData(root, data);
    }

private:
    BinaryTreeNode<int>* insertD(BinaryTreeNode<int> *node, int k)
    {
        if (node == NULL)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(k);

            node = newNode;
        }
        else if (k < node->data )
        {
            node->left = insertD(node->left, k);
            
        }else{
            node->right = insertD(node->right, k);
            
        }
        return node;
    }

public:
    void insert(int data)
    {
        this->root = insertD(this->root, data);
    }

private:
    bool hasData(BinaryTreeNode<int> *node, int data)
    {
        if (node == nullptr)
            return false;
        if (node->data == data)
        {
            return true;
        }
        else if (node->data > data)
        {
            return hasData(node->left, data);
        }
        else
        {
            return hasData(node->right, data);
        }
        return false;
    }

public:
    bool haData(int data)
    {
        return hasData(root, data);
    }
};