#include<iostream>
#include<cstring>
using namespace std;
int codes(string s,string a[]){
    if(s.length()==0){
        a[0]="\0";
        return 1;
    }
    int t= (s[0]-'0');
    int c1= codes(s.substr(1),a);
        for(int i=0;i<c1;i++){
            a[i]=char(t+'a'-1) + a[i];
        }
    int x= (s[0]-'0')*10+(s[1]-'0');
    int c2=0;
    if(s.length()>1&&x>=10 &&x<=26){
        c2=codes(s.substr(2), a+c1 );
        for(int i=c1;i<c2+c1;i++){
            a[i]=char(x+'a'-1) + a[i];
        }
    }
    return c1+c2;
}
int main(){
    string s;
    cin>>s;
    int n=s.length();
    string* a=new string[100];
    int count=codes(s,a);
    for(int i=0;i<count;i++){
        cout<<a[i]<<endl;
    }
}