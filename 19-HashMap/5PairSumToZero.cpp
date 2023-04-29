/*Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.
Note: Array A can contain duplicate elements as well.*/
#include<iostream>
#include<unordered_map>
using namespace std;
int pairSumToZero(int a[],int n){
    unordered_map<int,int> mp;

    for(int i=0;i<n;i++){
        mp[a[i]]++;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int temp = -a[i];
        if(mp.count(temp)>0){
            ans+=mp[temp]*mp[a[i]];
            
            mp.erase(temp);
            mp.erase(a[i]);
        }
    }
    return ans;


}
int main(){
    int size;
    cin>>size;
    int a[size];
    for(int i=0;i<size;i++){
        cin>>a[i];
    }
    cout<<pairSumToZero(a,size)<<endl;

}