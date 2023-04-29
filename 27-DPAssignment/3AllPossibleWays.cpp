
/*

Chapter Assignment
Problem Statement: All possible ways
Problem Level: MEDIUM
Problem Description:
Given two integers a and b. You need to find and return the count of possible ways in which we can represent the number a as the sum of unique integers raise to the power b.
For eg. if a = 10 and b = 2, only way to represent 10 as -
10 = 1^2 + 3^2

Hence, answer is 1.
Note : x^y represents x raise to the power y
Inout Format :
Two integers a and b (separated by space)

Output Format :
Count

Constraints :
1 <= a <= 10^5
1 <= b <= 50

Sample Input 1 :
10 2

Sample Output 1 :
1

Sample Input 2 :
100 2


Sample Output 2 :
3

*/

#include<iostream>
#include<math.h>
using namespace std;
int allPossibleWays(int a,int b,int currNum,int currSum){
    if(currSum==a){
        return 1;
    }
    int ans=0;
    int p=pow(currNum+1,b);
    while(p+currSum<=a){
        ans+=allPossibleWays(a,b,currNum+1,currSum+p);
        currNum++;
        p=pow(currNum,b);
    }
    
    return ans;

}
int main(){
    int a;
    int b;
    cin>>a;
    cin>>b;
    cout<<allPossibleWays(a,b,1,0)<<endl;

}