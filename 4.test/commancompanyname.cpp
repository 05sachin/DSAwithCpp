#include<bits/stdc++.h>
using namespace std;
long long distinctNames(vector<string>& ideas) {
        unordered_map<int,unordered_set<string>> mp(26);

        for(auto x:ideas){
            int idx=x[0]-'a';
            mp[idx].insert(x.substr(1));
        }
        long long ans=0;
        
        for(int i=0;i<26;i++){
            
            for(int j=i+1;j<26;j++){
                long long count=0;
                for(auto x:mp[j]){
                    if(mp[i].find(x)!=mp[i].end()){
                        count++;
                    }
                }

                int n=mp[i].size()-count;
                int m=mp[j].size()-count;
                
                ans+=(n*m)*2;

            }
        }
        return ans;

    }
int main(){
    vector<string> ideas = {"aaa","baa","caa","bbb","cbb","dbb"};
    cout<<distinctNames(ideas)<<" ";
}
