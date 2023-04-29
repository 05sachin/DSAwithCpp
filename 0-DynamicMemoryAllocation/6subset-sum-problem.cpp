#include<iostream>
using namespace std;
int countsum(int arr[],int n,int sum){
    if(n==0){
        return (sum==0)? 1:0;
    }
    return countsum(arr,n-1,sum)+countsum(arr,n-1,sum-arr[n-1]);
}
int main(){
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
    cin>>arr[i];
}
int sum;
cin>>sum;
cout<<countsum(arr,n,sum)<<endl;
}