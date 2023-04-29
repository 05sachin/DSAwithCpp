#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
bool solve(string& s){
    stack<int> st;
    for(int i=0;i<s.length();i++){
        if(s[i]==')'){
            int c=0;
            while(st.top()!='('){
                st.pop();
                c++;
            }
            st.pop();
            if(c<=1){
                return true;
            }
        }else{
            st.push(s[i]);
        }
    }
    return false;
}
int main(){
    string s;
    cin>>s;
    cout<<solve(s)<<endl;
}