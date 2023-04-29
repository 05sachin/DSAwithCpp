/*Problem Description:
You are given a stream of N integers. For every i-th integer added to the running list of integers, print the resulting median.
Print only the integer part of the median.*/
#include <iostream>
#include <queue>
using namespace std;

void runningMedian(int arr[], int n)
{
    priority_queue<int> pql;
    priority_queue<int, vector<int>, greater<int>> pqr;

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            pql.push(arr[i]);
        }
        else
        {
            if (arr[i] < pql.top())
            {
                pql.push(arr[i]);
            }
            else
            {
                pqr.push(arr[i]);
            }
        }
    // size checking
        if ((int)(pql.size() - pqr.size()) > 1)
        {
            int x=pql.top();
            pql.pop();
            pqr.push(x);
        }

        else if((int)(pqr.size()-pql.size()) > 1){
            
            int x=pqr.top();
            pqr.pop();
            pql.push(x);
        }

        if((pql.size()+pqr.size())%2==0){
            cout<<(pql.top()+pqr.top())/2<<endl;

        }else if(pql.size()>pqr.size()){
            cout<<pql.top()<<endl;
        }else{
            cout<<pqr.top()<<endl;
        }
    }

}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    runningMedian(arr, n);
}