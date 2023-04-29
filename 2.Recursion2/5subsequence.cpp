#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int subs(string s,string op[]){
    if(s.empty()){
        op[0]=" ";
        return 1;
    }
    string smallstring=s.substr(1);
    int count=subs(smallstring,op);
    for(int i=0;i<count;i++){
        op[count+i]=s[0]+op[i];
    }
    return 2*count;
}
int main(){
    string s;
    cout<<"enter string"<<endl;
    cin>>s;
    int n=s.size();
    int m=pow(2,n);
    string* output = new string[m];
    int count=subs(s,output);
    cout<<count<<endl;
    for(int i=0;i<count;i++){
        cout<<output[i]<<endl;
    }
}