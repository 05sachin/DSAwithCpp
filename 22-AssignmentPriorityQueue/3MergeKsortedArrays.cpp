/*Problem Description:
Given k different arrays, which are sorted individually (in ascending order). You need to merge all the given arrays such that output array should be sorted (in ascending order).
Hint : Use Heaps.*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> mergeKSortedArrays(vector<vector<int>>& arr,int k){
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    vector<int> ans;
    for(int i=0;i<k;i++){
        pq.push({arr[i][0],i,0});
    }

    while(!pq.empty()){
        vector<int> x = pq.top();

        pq.pop();
        ans.push_back(x[0]);

        if( x[2] >= arr[(x[1])].size()-1){
            continue;
        }
        
        pq.push({arr[x[1]][x[2]+1],x[1],x[2]+1});

    }
    return ans;
}
int main(){
    int k;
    cin>>k;
    vector<vector<int>> arr(k);
    for(int i=0;i<k;i++){
        
        int n;
        cin>>n;
        arr[i].resize(n);
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    vector<int> ans = mergeKSortedArrays(arr,k);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}