#include<iostream>
using namespace std;
void permu(string s,string curr=""){
    if(s.size()==0){
    cout<<curr<<endl;
    return ;
    }
    for(int pos=0;pos<s.size();pos++){
        permu(s.substr(0,pos)+s.substr(pos+1),curr+s[pos]);
    }
    

}
int main(){
    string s;
    cin>>s;
    cout<<endl;
    permu(s);
}