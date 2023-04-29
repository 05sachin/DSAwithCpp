#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//naive sol
// int main(){
//     int n=5;
//     int res=0;
//     while(n>0){     // res=res+(n&1)
//         if(n&1!=0)//n%2!=0
//         {
//             res++;
           
//         }
//         n=n>>1;//n=n/2
//     }
//     cout<<res<<endl;
// }
//brean kerningam's solution
/*int main(){
    int n=40;
    int res=0;
    while(n>0){
        n=n&(n-1);
        res++;      //O(res)

    }
    cout<<res<<endl;

}*/
//lookup table method for 32 bit number
int count(int n){
    int table[256];
    table[0]=0;
    for(int i=1;i<256;i++){
        table[i]=(i&1)+table[i/2];

    }
    int res=table[n&0xff];//theta 1
    n=n>>8;
    res=res+table[n&0xff];
    n=n>>8;
    res=res+table[n&0xff];
    n=n>>8;
    res=res+table[n&0xff];
    return res;
}
int main(){
    int n=40;
    cout<<count(n)<<endl;
}
