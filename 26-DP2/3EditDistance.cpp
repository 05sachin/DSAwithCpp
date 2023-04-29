/*Coding Problem
Problem Statement: Edit Distance
Problem Level: MEDIUM
Problem Description:
Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance of two strings is minimum number of steps required to make one string equal to other. In order to do so you can perform following three operations only :
1. Delete a character

2. Replace a character with another one

3. Insert a character

Note - Strings don't contain spaces
Input Format :
Line 1 : String s
Line 2 : String t

Output Format :
Line 1 : Edit Distance value

Constraints
1<= m,n <= 10

Sample Input 1 :
abc
dc

Sample Output 1 :
2
*/

#include <iostream>
#include <climits>
#include <string>

using namespace std;
int editDistance(string s, string t)
{
    if (s.length() == 0 || t.length() == 0)
    {
        return max(s.length(), t.length());
    }

    int ans;
    int val1 = s[0];
    int val2 = t[0];
    if (val1 == val2)
    {
        ans = editDistance(s.substr(1), t.substr(1));
    }
    else
    {
        int d = editDistance(s, t.substr(1)) + 1;           // delete
        int r = editDistance(s.substr(1), t.substr(1)) + 1; // replace
        int i = editDistance(s.substr(1), t) + 1;           // insert

        ans = min(d, min(i, r));
    }
    return ans;
}
int editDistanceMemo(string s, string t, int **dp)
{
    int i = s.length();
    int j = t.length();
    if (s.length() == 0 || t.length() == 0)
    {
        return dp[i][j] = max(s.length(), t.length());
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int ans;
    int val1 = s[0];
    int val2 = t[0];
    if (val1 == val2)
    {
        ans = editDistanceMemo(s.substr(1), t.substr(1), dp);
    }
    else
    {
        int d = editDistanceMemo(s, t.substr(1), dp) + 1;           // delete
        int r = editDistanceMemo(s.substr(1), t.substr(1), dp) + 1; // replace
        int i = editDistanceMemo(s.substr(1), t, dp) + 1;           // insert

        ans = min(d, min(i, r));
    }
    return dp[i][j] = ans;
}
int editDistance_1(string s, string t)
{
    int **dp = new int *[s.length() + 1];
    for (int i = 0; i <= s.length(); i++)
    {
        dp[i] = new int[t.length() + 1];
        for (int j = 0; j <= t.length(); j++)
        {
            dp[i][j] = -1;
        }
    }

    return editDistanceMemo(s, t, dp);
}
int editDistanceTabu(string s, string t)
{
    if (s.length() == 0 || t.length() == 0)
    {
        return max(s.length(), t.length());
    }


    int **dp = new int *[s.length() + 1];
    for (int i = 0; i <= s.length(); i++)
    {
        dp[i] = new int[t.length() + 1];
        dp[i][t.length()] = s.length()-i;
        if(i==s.length()){
            for(int j=0;j<=t.length();j++){
                dp[i][j] = t.length()-j;
            }
        }
        
    }
    
    for (int i = s.length() - 1; i >= 0; i--)
    { 
       

        for (int j = t.length() - 1; j >= 0; j--)
        {
            
            int ans;
            
            if (s[i] == t[j])
            {
                ans = dp[i+1][j+1];
            }
            else
            {
                int d = dp[i][j+1] + 1;           // delete
                int r = dp[i+1][j+1] + 1; // replace
                int p = dp[i+1][j] + 1;           // insert
                
                ans = min(d, min(p, r));
            
            }
            dp[i][j]=ans;
           
        }
    }
    


    return dp[0][0];
}
int main()
{
    string s;
    string t;

    cin >> s;
    cin >> t;

    
    cout << editDistance_1(s, t) << endl;
    cout << editDistanceTabu(s, t) << endl;
    // cout<<editDistance(s,t)<<endl;
}