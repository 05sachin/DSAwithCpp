/*Problem Description:
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so return output modulus 10^9 + 7.
Write a simple recursive solution.*/

#include<iostream>
#include<cmath>
#define p 1000000007
using namespace std;

int noOfBalancedBinaryTree(int h){
    
    if(h<=1){
        return 1;
    }
    if(h==2) return 3;
    
    int count1 = noOfBalancedBinaryTree(h-1);// (h-1 ,h-2 ) (h-2,h-1) (h-1,h-1)

    int count2 = noOfBalancedBinaryTree(h-2);
    int temp1 = (int)(((long long )(count1) * count1)%p);
    int temp2 =(int)((2*(long long )(count1) *count2)%p);
    int total =  (temp1+temp2 )%p;
    return total;


}
int noOfBalancedBinaryTree_1Info(int h,int* arr){
    
    if(h<=1){
        return arr[h]=h;
    }
    if(h==2){
        return arr[2]=3;
    }
    if(arr[h]!=-1) return arr[h];
    int count1 = noOfBalancedBinaryTree_1Info(h-1,arr);// (h-1 ,h-2 ) (h-2,h-1) (h-1,h-1)

    int count2 = noOfBalancedBinaryTree_1Info(h-2,arr);
    int total = (int)(((long long )(count1)*count1)%p) + (int)((2*(long long)(count2)*count1)%p);
    return arr[h]=total%p;


}
int noOfBalancedBinaryTree_1(int h){
    
    int* arr = new int[h+1];
    for(int i=0;i<=h;i++){
        arr[i]=-1;
    }
    return noOfBalancedBinaryTree_1Info(h,arr);
}
int noOfBalancedBinaryTree_2(int h){
    
    int* arr = new int[h+1];
    arr[0]=0;
    arr[1]=1;
    arr[2]=3;
    for(int i=3;i<=h;i++){
        int count1 = arr[i-1];// (h-1 ,h-2 ) (h-2,h-1) (h-1,h-1)

        int count2 = arr[i-2];
        int total = (int)(((long long)(count1)*count1)%p) + (int)((2*(long long)(count2)*count1)%p);
        arr[i]=total%p;
    }
    return arr[h];

}
int main(){
    int h;
    cin>>h;
    
    cout<<noOfBalancedBinaryTree(h)<<endl;
    cout<<noOfBalancedBinaryTree_1(h)<<endl;
    cout<<noOfBalancedBinaryTree_2(h)<<endl;
}