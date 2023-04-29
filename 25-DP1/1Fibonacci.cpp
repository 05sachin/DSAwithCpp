#include<iostream>
using namespace std;
int fibo(int n){
    if(n<=1){
        return n;
    }
    return fibo(n-1)+fibo(n-2);
}

int fibo_helper(int n,int *ans){
    if(n<=1){
        return ans[n]=n;
    }
    // check if output  already exist
    if(ans[n]!=-1){
        return ans[n];
    }

    int a = fibo_helper(n-1,ans)+fibo_helper(n-2,ans);
    return ans[n]=a;
}

int fibo2(int n){
    int ans[n+1];
    for(int i=0;i<=n;i++){
        ans[i]=-1;
    }
    return fibo_helper(n,ans);
}

int fibo_3(int n){
    int* a = new int[n+1];
    a[0]=0;
    a[1]=1;

    for(int i=2;i<=n;i++){
        a[i]=a[i-1]+a[i-2];
    }
    return a[n];

}
int main(){
    int n;
    cin>>n;
    cout<<fibo(n)<<endl;
    cout<<fibo2(n)<<endl;
    cout<<fibo_3(n)<<endl;
}