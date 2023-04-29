#include<iostream>
using namespace std;
void divisor(int n){
    int i;
    for(i=1;i*i<n;i++){
        if(n%i==0){
            cout<<i<<endl;
        }
    }
    if(i-(n/i)==1){
        i--;
    }
    for(;i>=1;i--){
        if(n%i==0){
            cout<<n/i<<endl;
        }
    }
}
int main(){
    int n;
    cout<<"enter the number:"<<endl;
    cin>>n;
    divisor(n);
    return 0;
}