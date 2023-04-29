#include<iostream>
#include<unordered_map>
#include<climits>
using namespace std;
int maximumFrequency(int a[],int size){
    unordered_map<int,int> mp;

    for(int i=0;i<size;i++){
        mp[a[i]]++;
    }
    int m=0;
    int maxVal;
    for(int i=0;i<size;i++){
        if(mp[a[i]]>m){
            m=mp[a[i]];
            maxVal=a[i];
        }
    }
    return maxVal;
}
int main(){
    int size;
    cin>>size;

    int a[size];

    for(int i=0;i<size;i++){
        cin>>a[i];
    }

   cout<<maximumFrequency(a,size)<<endl;
}