#include<iostream>
using namespace std;
bool palind(string &s,int sp,int ep ){
    if(sp>=ep){
        return true;
    }
    return (s[sp]==s[ep]) && palind(s,sp+1,ep-1);
}
int main()
{
  string s="abjhghjdyhdba";
  int n=s.length();
  cout<<palind(s,0,n-1);  
}