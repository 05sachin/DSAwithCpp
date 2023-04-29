#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include "BinaryTreeNode.h"
using namespace std;
void check(string s,unordered_map<char ,string>& mp1,unordered_map<string,char>& mp2){
    string ans="";
    for(char ch:s){
       ans=ans+ mp1[ch];
    }
    cout<<ans<<endl;
    string ans1="";

    int i=0;
    string check="";
    while(i!=ans.length()){
       
        check=check+ans[i];
        if(mp2.count(check)>0){
            ans1=ans1+mp2[check];
            check="";
        }
        i++;
    }
    cout<<ans1<<endl;
}
void storeMap(BinaryTreeNode<char>* root,unordered_map<char,string>& mp1,unordered_map<string,char>& mp2,string s=""){
    if(root==nullptr){
        return ;
    }
    if(root->left==nullptr && root->right==nullptr){
        mp1[root->data]=s;
        mp2[s]=root->data;
        return;
    }
    
    storeMap(root->left,mp1,mp2,s+'0');
    storeMap(root->right,mp1,mp2,s+'1');

}
BinaryTreeNode<char>* constructInvertedBinaryTree( priority_queue<pair<int ,BinaryTreeNode<char>*>,vector<pair<int,BinaryTreeNode<char>*>>,greater<pair<int,BinaryTreeNode<char>*>>>& pq){
    if(pq.size()==0){
        return nullptr;
    }
    BinaryTreeNode<char>* root=nullptr;
    while(!pq.empty()){
        if(pq.size()==1){
            pair<int,BinaryTreeNode<char>*> p = pq.top();
            pq.pop();
            if(p.second->data=='\0'){
                root=p.second;
                continue;
            }
            BinaryTreeNode<char>* node = new BinaryTreeNode<char>('\0');
            node->left = p.second;
            
            root=node; 

        }else{
            pair<int,BinaryTreeNode<char>*> p1 = pq.top();
            pq.pop();

            pair<int,BinaryTreeNode<char>*> p2 = pq.top();
            pq.pop();
            BinaryTreeNode<char>* node = new BinaryTreeNode<char>('\0');
            node->left = p2.second;
            node->right = p1.second;
            pq.push({p1.first+p2.first,node});

        }
        
    }
    return root;
}
int main(){
    string s;
    cin>>s;

    vector<int> v(26,0);
     // frequency array
    for(char ch:s){
        v[ch-'a']++;
    }
    // min  priority_queue 
    priority_queue<pair<int ,BinaryTreeNode<char>*>,vector<pair<int,BinaryTreeNode<char>*>>,greater<pair<int,BinaryTreeNode<char>*>>> pq;

    for(int i=0;i<26;i++){
        if(v[i]>0){
            BinaryTreeNode<char>* node = new BinaryTreeNode<char>(i+'a');
            pq.push({v[i],node});
        }
    }
    BinaryTreeNode<char>* root = constructInvertedBinaryTree(pq);
    unordered_map<char,string> mp1;// char,bit code
    unordered_map<string,char> mp2;// bit code ,char
    storeMap(root,mp1,mp2);
    string p;
    cin>>p;
    check(p,mp1,mp2);
    


}