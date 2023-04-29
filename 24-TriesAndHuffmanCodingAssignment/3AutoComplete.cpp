/*Problem Description:
Given n number of words and an incomplete word w. You need to auto-complete that word w.
That means, find and print all the possible words which can be formed using the incomplete word w.
Note : Order of words does not matter.*/
#include<iostream>
#include "Trie.h"
using namespace std;
void allPossibleWords(TrieNode* root,string word){
    if(root==nullptr){
        return;
    }
    if(root->isTerminal){
        cout<<word<<endl;
    }
    for(int i=0;i<26;i++){
        if(root->children[i]){
            allPossibleWords(root->children[i],word+root->children[i]->data);
        }
    }

}
int main(){
    int n;
    cin>>n;
    string arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    string word;
    cin>>word;
    Trie t;
    for(int i=0;i<n;i++){
        t.insertWord(arr[i]);
    }
    
    TrieNode* root =t.findWord(word); 
    allPossibleWords(root,word);

}