#include<iostream>
using namespace std;
int fun(int arr[],int n){
    int totalSum=0;
    for(int i=0;i<n;i++){
        totalSum+=arr[i];
    }

    int sum=0;

    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(totalSum+arr[i]==2*sum){
            return i+1;
        }
    }
    return -1;

}
int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<fun(arr,n)<<endl;
}