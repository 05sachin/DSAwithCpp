/*Problem Description:
Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.*/

#include<iostream>
#include<unordered_map>
#include<climits>
using namespace std;
int longestSubsetZeroSum(int a[],int n){
    unordered_map<int,int> mp;
    int maxLen=INT_MIN;
    int sum=0;
    mp[sum]=-1;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(mp.count(sum)>0){
            int len=i-mp[sum];
            maxLen=max(maxLen,len);
        }else{
            mp[sum]=i;
        }
        
    }
    return maxLen;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<longestSubsetZeroSum(a,n)<<endl;
}