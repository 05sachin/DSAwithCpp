#include<iostream>
using namespace std;
void printsubset(int n,int ip[],int op[],int s ){
    if(n==0){
        for(int i=0;i<s;i++){
            cout<<op[i]<<" ";
        }
        cout<<endl;
        return ;
    }
    printsubset(n-1,ip+1,op,s);
    op[s]=ip[0];
    printsubset(n-1,ip+1,op,s++);
    
}
int main(){
    int n;
    cin>>n;
    int ip[n];
    for(int i=0;i<n;i++){
        cin>>ip[i];
    }
    
    int op[n];
    printsubset(n,ip,op,0);

}