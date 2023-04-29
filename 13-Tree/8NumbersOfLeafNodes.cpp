#include<iostream>
#include<vector>
#include<queue>
#include "TreeNode.h"
using namespace std;

void printTreeLevelWise(TreeNode<int>* root){
    if(root==NULL) return ;
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int>* node = q.front();
        q.pop();
        cout<<node->data <<": ";
        for(int i=0;i<node->children.size();i++){
            q.push(node->children[i]);
            cout<<node->children[i]->data<<",";
        }
        cout<<endl;
    }
}
int leafNodes(TreeNode<int>* root){
    if(root==NULL) return -1;
    if(root->children.size()==0) return 1;
    int ans=0;
    for(int i=0;i<root->children.size();i++){
        ans+=leafNodes(root->children[i]);
    }
    return ans;
}
TreeNode<int>* inputTreeLevelWise(){
    int data;
    cout<<"Enter root element: "<<endl;
    cin>>data;
    TreeNode<int>* root = new TreeNode<int>(data);
    queue<TreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty()){
        TreeNode<int>* node = q.front();
        q.pop();
        int n;
        cout<<"Enter no. of childrens of  "<<node->data<<endl;
        cin>>n;
        
        for(int i=0;i<n;i++){
            int childData;
            cout<<"Enter "<<i+1<<"th child of node "<<node->data<<endl;
            cin>>childData;

            TreeNode<int>* child = new TreeNode<int>(childData);
            node->children.push_back(child);

            q.push(child);
        }

    }
    return root;

}
int main(){
    /*TreeNode<int>* root=new TreeNode<int>(1);
    TreeNode<int>* node1=new TreeNode<int>(2);
    TreeNode<int>* node2=new TreeNode<int>(3);

    root->children.push_back(node1);
    root->children.push_back(node2);*/
    TreeNode<int>* root = inputTreeLevelWise();
    printTreeLevelWise(root);
    cout<<"Number of leaf nodes : "<<leafNodes(root)<<endl;
    

}
