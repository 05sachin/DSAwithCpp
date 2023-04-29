#include<iostream>
using namespace std;
int mul(int m, int n){
    if(n==0){
        return 0;
    }
    int ans =mul(m,n-1);
    return m+ans;
}
int main(){
    int m,n;
    cin>>m>>n;
    cout<<mul(m,n)<<endl;
}