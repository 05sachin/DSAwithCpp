/*Problem Description:
You are given an array of unique integers that contain numbers in random order. You have to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains starting and ending element. If the length of the longest possible sequence is one, then the output array must contain only single element.
Note:
1. Best solution takes O(n) time.
2. If two sequences are of equal length, then return the sequence starting with the number whose occurrence is earlier in the array.*/

#include<iostream>
#include<string>
#include<climits>
#include<unordered_map>
using namespace std;
pair<int,int> longestConsecutiveSequence(int a[],int n){
    if(n==1){
        return {a[0],a[0]};
    }
    int r1=INT_MAX;
    int r2=INT_MIN;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[a[i]]=i;
        r1=min(r1,a[i]);
        r2=max(r2,a[i]);
    }
    int start=a[0];
    int index=0;
    int maxLen=INT_MIN;
    for(int i=0;i<n;i++){
        if(mp[a[i]]!=-1){
            int s=a[i];
            int in=i;
            int len=0;
            mp[s]=false;
            int k=s+1;
            while(k<=r2 && mp.count(k) >0){
                mp[k]=-1;
                k++;
                len++;
            }
            k=s-1;
            while(k>=r1 && mp.count(k)>0){
                in=mp[k];
                mp[k]=-1;
                cout<<in<<endl;
                k--;
                len++;
            }
            
            s=k+1;
            if(len>maxLen){
                start=s;
                index=in;
                maxLen=len;
            }
            else if(len==maxLen && in<index){
                start=s;
                index=in;
                maxLen=len;
            }
            
            

        }
    }
    return {start,start+maxLen};
    

}
int main(){
    int size;
    cin>>size;

    int a[size];
    for(int i=0;i<size;i++){
        cin>>a[i];
    }
    pair<int ,int> p=longestConsecutiveSequence(a,size);
    cout<<p.first<<" "<<p.second<<endl;

}