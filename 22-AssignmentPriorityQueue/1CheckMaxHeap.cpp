/*Problem Description:
Given an array of integers, check whether it represents max-heap or not. Return true if the given array represents max-heap, else return false.*/
#include<iostream>
#include<queue>
using namespace std;
bool checkMaxHeap(int input[],int n,int i){
    
    int leftChildIndex=2*i+1;
    int rightChildIndex = 2*i+2;
    int ans=true;
    if(leftChildIndex < n){
        if(input[i] < input[leftChildIndex]){
            return false;
        }
        ans=ans && checkMaxHeap(input,n,leftChildIndex);
        if(rightChildIndex < n){
            if(input[i] < input[rightChildIndex]){
                return false;
            }
            ans = ans && checkMaxHeap(input,n,rightChildIndex);
        }

    }
    return ans;
}
int main(){
    int n;
    cin>>n;

    int input[n];

    for(int i=0;i<n;i++){
        cin>>input[i];
    }

    cout<<checkMaxHeap(input,n,0);
}