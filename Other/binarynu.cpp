#include<iostream>
using namespace std;
int binary(int n){
    if(n==0){
        return 0;
    }
    binary(n/2);
    cout<<n%2;
}
int main()
{
   int n=10;
   binary(n);
   return 0; 
}