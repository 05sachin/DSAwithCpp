// Given a generic tree, find and return the node with second largest value in given tree.
// Given a generic tree and an integer n. Find and return the node with next larger element in the tree i.e. find a node with value just greater than n.
#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include "TreeNode.h"
using namespace std;
pair<int,int> secondLargestRec(TreeNode<int>* root){
    if(root==NULL) return {INT_MIN,INT_MIN} ;
    pair<int,int> ans;
    ans.first=root->data;
    ans.second=INT_MIN;
    for(int i=0;i<root->children.size();i++){
        pair<int,int> temp=secondLargestRec(root->children[i]);
        if(ans.first<temp.first){
            int c=ans.first;
            ans.first=temp.first;
            if(c<temp.second){
                ans.second=temp.second;

            }else{
                ans.second=c;
            }
        }else if(ans.first>temp.first) {
            if(ans.second<temp.first){
                ans.second=temp.first;
            }
        }else{
            if(ans.second < temp.second){
                ans.second=temp.second;
            }
        }
    }
    return ans;


}
int secondLargest(TreeNode<int>* root){
    if(root==NULL) return INT_MIN;
    queue<TreeNode<int>*> q;
    q.push(root);
    int f=root->data;
    int s=INT_MIN;
    while(!q.empty()){
        TreeNode<int>* node = q.front();
        q.pop();
        if(f<node->data){
            s=f;
            f=node->data;
        }else if(s<node->data && node->data!=f){

            s=node->data;
        }
        for(int i=0;i<node->children.size();i++){
            q.push(node->children[i]);
        }
    }
    return s;
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
    cout<<" second largest: "<<secondLargest(root)<<endl;
    //another way
    cout<<"second largest: "<<secondLargestRec(root).second<<endl;
    

}