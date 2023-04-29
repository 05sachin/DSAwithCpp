#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//naive sol
/*bool poweroftwo(int n){
    if(n==0){
        return false;

    }
    while(n!=1){
        if(n&1){
            return false;
        }
        n=n/2;
    }
    return true;
}*/
int poweroftwo(int n){
    if(n==0){
        return false;
    }
    return n&(n-1)==0;
}
int main(){
    int n=5;
    cout<<poweroftwo(n)<<endl;

}