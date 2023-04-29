#include<iostream>
using namespace std;
int count(int n){
    if(n==0){
        return 1;
    }
    if(n<=9){
        return 0;
    }
    int rem=n%10;
    int ans=(rem==0)? 1:0;
    ans +=count(n/10);
    return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<count(n)<<endl;
}