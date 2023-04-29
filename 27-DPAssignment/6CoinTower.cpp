/*Chapter Assignment
Problem Statement: Coin Tower
Problem Level: MEDIUM
Problem Description:
Whis and Beerus are playing a new game today. They form a tower of N coins and make a move in alternate turns. Beerus plays first. In one step, the player can remove either 1,  X, or Y coins from the tower. The person to make the last move wins the game. Can you find out who wins the game?
Input format :
The first and the only line of input contains three integer values separated by a single space. They denote the value of N, X and Y, respectively.

Output format :
Prints the name of the winner, either 'Whis' or 'Beerus' (Without the quotes).

Constraints :
1 <= N <= 10 ^ 6
2 <= X <= Y<= 50

Time Limit: 1 sec

Sample Input 1 :
4 2 3

Sample Output 1 :
Whis

Sample Input 2 :
10 2 4

Sample Output 2 :
Beerus*/

#include<iostream>
using namespace std;
string  coinTower(int n,int x,int y){
    int dp[n+1]; // contains only 0 and 1
     // 0 for lost ,1 for won
    for(int i=2;i<=n;i++){
        if(i==x || i==y || i==1){
            dp[i]=1;
            continue;
        }
        int a1 = dp[i-1]^1;
        int a2=0;
        int a3=0;
        if(i>x){
            a2 = dp[i-x]^1;
        }
        if(i>y){
            a3 = dp[i-y]^1;
        }
        dp[i]=max(a1,max(a2,a3));
    }
    int check = dp[n];
    string ans ;
    if(check==1){
        ans="Beerus";
    }else{
        ans="Whis";
    }
    return ans;
}
int main(){
    int n,x,y;
    cin>>n>>x>>y;
    
    cout<<coinTower(n,x,y)<<endl;
}