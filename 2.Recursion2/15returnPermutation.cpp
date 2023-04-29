#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int permu(string s,string a[]){
    if(s.length()==0){
        a[0]="\0";
        return 1;
    }
    int x=permu(s.substr(1),a);
    int count=0;
    for(int i=0;i<x;i++){
        string p=a[i];
        a[i]=s[0]+a[i];
        for(int j=1;j<p.length()+1;j++){
            a[count+x]=p.substr(0,j)+s[0]+p.substr(j);
            count++;
        }
        
    }
    return count+x;
}
int main(){
    string s;
    cin>>s;
    string a[100];
    int count=permu(s,a);
    cout<<count<<endl;
    for(int i=0;i<count;i++){
        cout<<a[i]<<endl;
    }
}