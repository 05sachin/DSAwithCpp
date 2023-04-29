#include <iostream>
using namespace std;
int ways(int n)
{
    if (n<3)
    {
        return (n==0)?1: n;
    }
    int x = ways(n - 1);
    int y = ways(n - 2);
    int z = ways(n - 3);
    int ans = x + y + z;
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int w = ways(n);
    cout << w << endl;
}