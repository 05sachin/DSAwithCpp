#include<iostream>
#include<stack>
using namespace std;
bool check(string s){
    stack<char> st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('||s[i]=='{' || s[i] == '['){
            st.push(s[i]);
        }else if(s[i] == ')' || s[i]=='}' || s[i]==']'){
            if(s[i]==')' && st.top()=='('){
                st.pop();
            }else if(s[i]=='}' && st.top()=='{'){
                st.pop();
            }else if(s[i]==']' && st.top()=='['){
                st.pop();
            }else{
                return false;
            }
        }
    }
    if(!st.empty()) return false;
    return true;
}
int main(){
    string s;
    cin>>s;
    cout<<check(s)<<endl;
}