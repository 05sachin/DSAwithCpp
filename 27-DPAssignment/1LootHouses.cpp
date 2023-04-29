/*@csalgo

Chapter Assignment
Problem Statement: Loot Houses
Problem Level: MEDIUM
Problem Description:
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Input format :
The first line of input contains an integer value of 'n'. It is the total number of houses.

The second line of input contains 'n' integer values separated by a single space denoting the amount of money each house has.

Output format :
Print the the maximum money that can be looted.

Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec

Sample Input 1 :
6
5 5 10 100 10 5

Sample Output 1 :
110

Sample Input 2 :
6
10 2 30 20 3 50

Sample Output 2 :
90

Explanation of Sample Output 2 :
Looting first, third, and the last houses([10 + 30 + 50]) will result in the maximum loot, and all the other possible combinations would result in less than 90.



=====Answer=====
Correct Option: 

@csalgo*/
#include<iostream>
using namespace std;
int lootHouses(int* arr ,int n,int i){
    if(i>=n){
        return 0;
    }
    
    int ans=max(arr[i]+lootHouses(arr,n,i+2),lootHouses(arr,n,i+1));
    return ans;

}
int lootHousesMemo(int* arr ,int n,int i,int* dp){
    if(i>=n){
        return 0;
    }
    if(i==n-1){
        return dp[i]=arr[i];
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int ans=max(arr[i]+lootHousesMemo(arr,n,i+2,dp),lootHousesMemo(arr,n,i+1,dp));
    return dp[i]=ans;

}

int lootHouses_1(int* arr,int n){
    int* dp= new int[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=-1;
    }
    return lootHousesMemo(arr,n,0,dp);
}
int lootHousesTab(int* arr ,int n){
    int* dp= new int[n+2];
    for(int i=0;i<=n+1;i++){
        dp[i]=0;
    }

    for(int i=n-1;i>=0;i--){
        int ans=max(arr[i]+dp[i+2],dp[i+1]);
        dp[i]=ans;
    }
    
    
    return dp[0];

}
int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<lootHouses_1(arr,n)<<endl;
    cout<<lootHousesTab(arr,n)<<endl;

    cout<<lootHouses(arr,n,0)<<endl;
}