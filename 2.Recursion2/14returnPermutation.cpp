#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int permu(string s,string a[]){
    if(s.length()==0){
        a[0]="\0";
        return 1;
    }
    int count=0;
    for(int i=0;i<s.size();i++){
        int x=permu(s.substr(0,i)+s.substr(i+1),a+count);
        for(int j=count;j<count+x;j++){
            a[j]=s[i]+a[j];
        }
        count+=x;
    }
    return count;
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