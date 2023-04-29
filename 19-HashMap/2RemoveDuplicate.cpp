#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> removeDuplicate(int* a,int size){
    vector<int> ans;
    unordered_map<int,bool> mp;
    for(int i=0;i<size;i++){
        if(mp.count(a[i])==0 ){
            ans.push_back(a[i]);
            mp[a[i]]=true;
        }
    }
    return ans;
}
int main(){
    int a[]={1,2,3,3,2,1,4,3,6,5,5};
    vector<int> ans=removeDuplicate(a,11);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";  
    }

}