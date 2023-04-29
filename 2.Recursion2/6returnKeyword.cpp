#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;
void keysubs(int n,string key[],vector<string> &op){
    if(n==0){
       op.push_back("");
       return ;
    }
    
    keysubs(n/10,key,op);
    int rem=n%10;

    string ch=key[rem];
    int p=op.size();
    string cp[p];
    for(int i=0;i<p;i++){
        cp[i]=op[i];
    }
    
    for(int i=0;i<ch.length();i++){
        for(int j=0;j<p;j++){
            if(i==0){
                op[j] = op[j] + ch[i];
            }
            else{
                op.push_back(cp[j]+ch[i]);
            }
        }
    }
}
int main(){
    int n;
    cout<<"enter number"<<endl;
    cin>>n;
    string key[10]= {",","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> op;
    keysubs(n,key,op);
    for(int i=0;i<op.size();i++){
        cout<<op[i]<<endl;
    }
    
}