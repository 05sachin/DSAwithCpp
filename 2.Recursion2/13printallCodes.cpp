#include<iostream>
#include<cstring>
using namespace std;
void codes(string s,string curr=""){
    if(s.length()==0){
        cout<<curr<<endl;
        return;
    }
    int t= (s[0]-'0');
    char c1= t+'a'-1;
    codes(s.substr(1),curr+c1 );
    int x= (s[0]-'0')*10+(s[1]-'0');
    char c2=x+'a'-1;
    if(s.length()>1&&x>=10 &&x<=26){
        codes(s.substr(2),curr +c2 );
    }
}
int main(){
    string s;
    cin>>s;
    codes(s);
    
}