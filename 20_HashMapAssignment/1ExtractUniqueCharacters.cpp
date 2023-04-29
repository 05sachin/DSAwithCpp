// Given a string S, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same, as in the input string.
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
void extractUniqueCharacters(string &s){
    unordered_map<char,int> mp;
    for(int i=0;i<s.length();i++){
        mp[s[i]]++;
    }
    string ans="";
    for(int i=0;i<s.length();i++){
        if(mp.count(s[i])>0 ){
            ans=ans+s[i];
            mp.erase(s[i]);
        }
        
    }
    s=ans;
}
int main(){
    string s;
    cin>>s;
    extractUniqueCharacters(s);
    for(char c:s){
        cout<<c;
    }

}