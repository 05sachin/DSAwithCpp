#include<iostream>
using namespace std;
void TOH (int n,char s,char a,char d){
    if(n==0){
        return ;
    }
    TOH(n-1,s,d,a);
    cout<<s<<"->"<<d<<endl;
    TOH(n-1,a,s,d);
}
int main(){
    int n;
    cin>>n;
    TOH(n,'S','A','D');
}
