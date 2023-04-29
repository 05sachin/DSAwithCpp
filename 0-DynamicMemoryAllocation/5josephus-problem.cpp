#include<iostream>
using namespace std;
int josephus(int n,int k){
    if(n==1){
        return 0;
    }
    return (josephus(n-1,k)+k)%n;
}
int main(){
int n,k;
cout<<"enter the value of n and k:"<<endl;
cin>>n;
cin>>k;
cout<<josephus(n,k)+1<<endl;
}