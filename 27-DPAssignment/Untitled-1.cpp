#include <iostream>
using namespace std;
void swap(int *p,int *v)
{
    int temp=*p;
    *p=*v;
    *v=temp;
}

int main()
{
    int a[8]={23,4,1,22,10,5,11,9};

    for(int i=7;i>=0;i--)
    {
        for(int j=0;j<=i;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(&a[j],&a[j+1]);

            }

        }
       
    }
    cout<<"the largest value is"<<" "<<a[7]<<endl;
    for(int i=0;i<8;i++)
    {
        cout<<a[i]<<" ";
    }

}
