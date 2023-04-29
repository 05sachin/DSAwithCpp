/*Problem Description:
You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k smallest numbers from given array. You need to save them in an array and return it.
Time complexity should be O(nlogk) and space complexity should be not more than O(k).
Order of elements in the output is not important.*/

#include<iostream>
#include<queue>
using namespace std;

priority_queue<int,vector<int>,greater<int>>* kLargestElements(int input[],int n,int k){
    priority_queue<int,vector<int>,greater<int>>* pq = new priority_queue<int,vector<int>,greater<int>>();

    for(int i=0;i<n;i++){
        if(i<k){
            pq->push(input[i]);
        }else{
            int temp = pq->top();
            if(temp < input[i]){
                pq->pop();
                pq->push(input[i]);
            }else{
                continue;
            }

        }
    }
    return pq;

    
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

    priority_queue<int,vector<int>,greater<int>>* pq= kLargestElements(input,n,k);
    cout<<"---------------------------------"<<endl;
    while(!pq->empty()){
        cout<<pq->top()<<endl;
        pq->pop();
    }
}