/*You have been given two integer arrays/list(ARR1 and ARR2) of size N and M, respectively. You need to print their intersection; An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in both the arrays/lists.
Note :
Input arrays/lists can contain duplicate elements.

The intersection elements printed would be in the order they appear in the first sorted array/list(ARR1).*/

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
vector<int> intersaction(int a[],int b[],int m,int n ){
    vector<int> ans;

    unordered_map<int ,int> mp;

    for(int i=0;i<m;i++){
        mp[a[i]]++;
    }
    
    for(int i=0;i<n;i++){
        if(mp.count(b[i])>0){
            ans.push_back(b[i]);
            
            mp[b[i]]--;
            if(mp[b[i]]==0){
                mp.erase(b[i]);
            }
        }
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    
    while(t--){
        int m;
        int n;
        cin>>m;
        int a[m];
        for(int i=0;i<m;i++){
            cin>>a[i];
        }

        cin>>n;
        int b[n];
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        cout<<"---------------"<<endl;
        vector<int> ans=intersaction(a,b,m,n);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        cout<<"--------------------"<<endl;


    }
}