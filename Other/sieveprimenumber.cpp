// naive solution
/*#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int isPrime(int n){
    for(int i=2;i*i<=n;i++){

        if(n%i==0){
            return false;

        }
    }
    return true;

}
void printprime(int n){
    for(int i=2;i<=n;i++){
        if(isPrime(i)){
            cout<<(i)<<endl;

        }
    }
}
int main(){
    int n;
    cout<<"enter the last number";
    cin>>n;
    printprime(n);
}*/
// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// void sieve(int n){
//     vector<bool>isPrime(n+1,true);
//     for(int i=2;i*i<=n;i++){
//         if(isPrime[i]){
//             for(int j=i*i;j<=n;j=j+i){
//                 isPrime[j]=false;
//             }                            //optimal code
//         }
//     }
//     for(int i=2;i<=n;i++){
//         if(isPrime[i]){
//             cout<<i<<endl;
//         }
//     }
// }
// int main(){
//     int n;
//     cout<<"enter the last number";
//     cin>>n;
//     sieve(n);
// }
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void sieve(int n){
    vector<bool>isPrime(n+1,true);
    for(int i=2;i<=n;i++){             //shortest optimal code nloglogn
        if(isPrime[i]){
            cout<<i<<endl;
            for(int j=i*i;j<=n;j=j+i){
                isPrime[j]=false;
            }
        }
    }
}
int main(){
    int n;
    cout<<"enter the last number";
    cin>>n;
    sieve(n);
}