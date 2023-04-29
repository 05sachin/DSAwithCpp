#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int sti(string s){
    if(s.length()==1){
       int ans=s[0]-'0';
       return ans;
    }
    int l=s.length()-1;
    int ans=sti(s.substr(0,l));
    int b=s[l] -'0';
    ans=ans*10+b;
    return ans;

}
int main(){
    string s;
    cin>>s;
    cout<<sti(s)<<endl;

}