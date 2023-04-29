#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
void strper(string s,int i){
    if(i==s.length()-1){
        cout<<s<<" ";
        return ;
    }
    for(int j=i;j<s.length();j++){
        swap(s[i],s[j]);
        strper(s,i+1);
        swap(s[i],s[j]);
    }
}
int main(){
    string s;
    cin>>s;
    strper(s,0);
} 