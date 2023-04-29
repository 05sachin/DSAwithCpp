#include<iostream>
using namespace std;
int main()
{
 int a[10];
 cout<<a<<endl;
 cout<<&a<<endl;
 cout<<a[0]<<endl;
 cout<<sizeof(a[0])<<endl;
 cout<<sizeof(a)<<endl;//a[0]=*(a+0)   a[1]=*(a+1)
 int *p=&a[0];
 int *q=a;
 cout<<p<<endl;
 cout<<q<<endl;
 cout<<&p+1<<endl;
 

}