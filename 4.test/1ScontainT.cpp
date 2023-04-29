#include<iostream>
using namespace std;
bool contain(string s,string t){
    if(t.size()==0) return true;
    int flag=0;
    int c=0;
    for(int i=0;i<s.size();i++){
        if(t[0]==s[i]){
            flag=1;
            c=i;
            break;
        }
    }
    if(flag==0){
        return false;
    }
    return contain(s.substr(c+1),t.substr(1));
}
int main(){
    string s;
    string t;
    cin>>s;
    cin>>t;
    cout<<contain(s,t);
}