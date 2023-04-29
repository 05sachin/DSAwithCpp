/*Problem Description:
Given 'n' number of words, you need to find if there exist any two words which can be joined to make a palindrome or any word, which itself is a palindrome.
The function should return either true or false. You don't have to print anything.*/
#include<iostream>
#include<cstring>
#include "Trie.h"
using namespace std;
bool itselfPalindrome(string w){
    int i=0;
    int j=w.length()-1;
    while(i<=j){
        if(w[i]!=w[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
bool palindromePair(string arr[],int n){
    Trie t;
    for(int i=0;i<n;i++){
        // if(itselfPalindrome(arr[i])){
        //     return true;
        // }
        t.insertWord(arr[i]);
        string rev = string(arr[i].rbegin(),arr[i].rend());
        if(t.search(rev)){
            return true;
        }
        
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    string arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<palindromePair(arr,n)<<endl;
}