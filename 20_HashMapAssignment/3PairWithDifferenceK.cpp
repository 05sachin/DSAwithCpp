/*Problem Description:
You are given with an array of integers and an integer K. You have to find and print the count of all such pairs which have difference K.
Note: Take absolute difference between the elements of the array.*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int pairWithDifferenceK(vector<int> &a, int n, int k)
{
    unordered_map<int, int> mp;
    int ans=0;
    for (int i = 0; i < n; ++i) { 
        int complement = a[i] + k; 
        ans += mp[complement]; 
        
        if (k != 0) {
            complement = a[i] - k; 
            ans += mp[complement]; 
        } 
        mp[a[i]]++; 
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int k;
    cin >> k;

    cout << pairWithDifferenceK(a,n,k) << endl;
}