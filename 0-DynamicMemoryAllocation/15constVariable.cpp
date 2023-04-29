#include<iostream>
using namespace std;
int main(){
    const int i=10;
    int const i2=12;
    // constant reference from a non const int
    int j=12;
    const int &k=j;
    j++;
    // k++ is not allow b/c of path has been constant
    cout<<k<<endl;
    // const reference from a const int
    int const j2=12;
    int const &k2=j2; 
    int const *p=&j2;  
}