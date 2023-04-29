#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    int n=str.length();
    int size=pow(2,n);
    for(int i=0;i<size;i++){
        for(int j=0;j<n;j++){
            if(((1<<j)&i)!=0){
                cout<<str[j];
            }
        }
        cout<<"\n";
    }
    return 0;
}