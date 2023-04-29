// Given a generic tree, find and return the node for which sum of its data and data of 
// all its child nodes is maximum. In the sum, data of the node and data of its immediate child nodes has to be taken.
#include<iostream>
#include<vector>
#include<queue>
#include "TreeNode.h"
using namespace std;
pair<int,int> nodeWithMaxChildSumRec(TreeNode<int>* root){
    pair<int,int> p;
    p.first=root->data;
    p.second=root->data;
    for(int i=0;i<root->children.size();i++){
        p.second+=root->children[i]->data;
    }

    for(int i=0;i<root->children.size();i++){
        pair<int ,int> s=nodeWithMaxChildSumRec(root->children[i]);
        if(s.second>p.second){
            p.second=s.second;
            p.first=s.first;
        }
    }

    return p;
}
int nodeWithMaxChildSum(TreeNode<int>* root){
    if(root==NULL) return -1;
    int maxSum=0;
    int nodeData=-1;
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int>* node = q.front();
        q.pop();
        int sum=node->data;
        
        for(int i=0;i<node->children.size();i++){
            sum+=node->children[i]->data;
            q.push(node->children[i]);
        }
        if(sum>maxSum){
            maxSum=sum;
            nodeData=node->data;
        }
    }
    return nodeData;
}
void printTreeLevelWise(TreeNode<int>* root){
    
    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode<int>* node = q.front();
        q.pop();
        cout<<node->data<<": ";
        for(int i=0;i<node->children.size();i++){
            cout<<node->children[i]->data<<",";
            q.push(node->children[i]);
        }
        cout<<endl;
    }
}
TreeNode<int>* inputLevelWise(){
    cout<<"Enter root data : "<<endl;
    int data;
    cin>>data;
    TreeNode<int>* root = new TreeNode<int>(data);
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int>* node = q.front();
        q.pop();
        int n;

        cout<<"Enter no. of Childrens of "<<node->data<<endl;
        cin>>n;
        for(int i=0;i<n;i++){
            int childData;
            cout<<"Enter "<<i+1<<"th Child element of " <<node->data<<endl;
            cin>>childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            node->children.push_back(child);
            q.push(child);

        }
    }
    return root;
}
int main(){
    TreeNode<int>* root = inputLevelWise();
    printTreeLevelWise(root);
    cout<<"node : "<<nodeWithMaxChildSum(root)<<endl;;
    //another way
    pair<int,int> ans = nodeWithMaxChildSumRec(root);
    cout<<"node : "<<ans.first<<endl;
    
    

}