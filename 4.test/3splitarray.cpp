#include<iostream>
using namespace std;
bool split1(int n ,int a[],int ls=0,int rs=0 ){
    if(n==0) return ls==rs;
    if(a[0]%5==0){
        rs+=a[0];
    }else if(a[0]%3==0){
        ls+=a[0];
    }else{
        return ( split1( n-1,a+1,ls+a[0],rs))|| (split1(n-1,a+1,ls,rs+a[0]));
    }
    return split1(n-1,a+1,ls,rs);
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<split1(n,a);

}