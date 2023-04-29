/*Problem Description:
Given an array A of random integers and an integer k, find and return the kth largest element in the array.
Note: Try to do this question in less than O(N * logN) time.*/

#include<iostream>
#include<queue>
using namespace std;
int kthLargestElement(int input[],int n,int k){
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<k;i++){
        pq.push(input[i]);
    }

    for(int i=k;i<n;i++){
        
        if( pq.top() < input[i] ){
            pq.pop();
            pq.push(input[i]);
        }
    }
    return pq.top();
}
int main(){
    int n;
    cin>>n;

    int input[n];
    for(int i=0;i<n;i++){
        cin>>input[i];
    }

    int k;
    cin>>k;
    cout<<kthLargestElement(input,n,k)<<endl;
}