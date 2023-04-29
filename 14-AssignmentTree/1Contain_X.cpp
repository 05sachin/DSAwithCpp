#include<iostream>
#include<vector>
#include<queue>
#include "TreeNode.h"
using namespace std;
bool containX(TreeNode<int>* root ,int x){
    if(root==NULL) return false;

    if(x==root->data) return true;
    bool flag =false;
    for(int i=0;i<root->children.size();i++){
        flag = flag ||  containX(root->children[i],x);
        if(flag){
            break;
        }
    }
    return flag;
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
    cout<<"enter value of X : ";
    int x;
    cin>>x;
    cout<<containX(root ,x)<<endl;

}