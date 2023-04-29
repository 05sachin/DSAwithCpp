/*Problem Description:
Given a  list of n words and a pattern p that we want to search. Check if the pattern p is present the given words or not. Return true if the pattern is present and false otherwise.*/
#include<iostream>
#include "SuffixTrie.h"
using namespace std;
bool patternMatching(string arr[],int n,string p){
    Trie t;
    for(int i=0;i<n;i++){
        string s=arr[i];
        for(int j=0;j<s.length();j++){
            t.insertWord(s.substr(j));
        }

    }
    return t.search(p);
}
int main(){
    int n;
    cin>>n;
    string arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    string p;
    cin>>p;
    cout<<patternMatching(arr,n,p)<<endl;
    
}