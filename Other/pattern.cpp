#include<iostream>
using namespace std;
int main(){
    for(int i=0;i<4;i++){
        for(int j=0;j<7;j++){
            if(j<3-i || j>3+i){
                cout<<" ";
            }else{
                if(j<=3){
                    cout<<j+i-2;
                }
                else {
                    cout<<i+6-j-2;
                }
            }


        }
        cout<<endl;
    }
return 0;
}