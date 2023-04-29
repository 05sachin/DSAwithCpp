#include<iostream>
using namespace std;
bool check(string s,int st,int lp){
    if(st>=lp){
        return true;
    }
    if(s[st]!=s[lp]){
        return false;
    }
    return check(s,st+1,lp-1);
}
int main(){
    string s;
    cin>>s;
    cout<<check(s,0,s.length()-1)<<endl;
}