#include<iostream>
using namespace std;
void removex( char s[]){
    if(s[0]=='\0'){
        return ;
    }
    if(s[0]!='x'){
        removex(s+1);
    }else{
        int i=1;
        for(;s[i]!='\0';i++){
            s[i-1]=s[i];
        }
        s[i-1]=s[i];
        removex(s);
    }
}
int length(char s[]){
    if(s[0]=='\0'){
        return 0;
    }
    int ans=length(s+1);
    return 1+ans;
}
int main(){
    char str[100];
    cin>>str;
    
    removex(str);
    cout<<str<<endl;
    int l=length(str);
    cout<<l<<endl;
}