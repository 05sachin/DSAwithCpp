/*Chapter Assignment
Problem Statement: Coding Ninjas
Problem Level: EASY
Problem Description:
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.
Input Format :
The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns in the matrix. 
Each of the following N lines contain M characters. Please note that characters are not space separated.

Output Format :
Print 1 if there is a path which makes the sentence “CODINGNINJA” else print 0.

Constraints :
1 <= N <= 1000
1 <= M <= 1000
Time Limit: 1 second

Sample Input 1:
2 11
CXDXNXNXNXA
XOXIXGXIXJX

Sample Output 1:
1*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class CN{
    int n;
    int m;
    char** s;
    int dr[8]={0,0,1,-1,-1,-1,1,1};
    int dc[8] ={1,-1,0,0,-1,1,-1,1};
    public:
    CN(int n,int m,char** s){
        this->n = n;
        this->m = m;
        this->s = s;
    }
    bool solve(string t,int i,int j,vector<vector<bool>> temp){
        if(t.size()==0) return true;
        if(i<0 || i>=n || j<0 || j>=m){
            return false;
        }
        
        if(temp[i][j]) return false;
        if(t[0]!=s[i][j]){
            return false;
        }
        temp[i][j]=true;
        
        for(int k=0;k<8;k++){
            int u = i+dr[k];
            int v = j+dc[k];
            if(u<0 || u>=n || v<0 || v>=m){
                continue;
            }
            if(!temp[u][v]){
               
               bool ans = solve(t.substr(1),u,v,temp);
               if(ans) return true;
            }
        }
        return false;
        

    }
    bool codingNinja(string t){
        vector<vector<bool>> temp(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(s[i][j]=='C'){
                    bool ans = solve(t,i,j,temp);
                    if(ans) return true;
                }
            }
        }
        return false;
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    char** s = new char*[n];

    for(int i=0;i<n;i++){
        s[i]=new char[m];
        for(int j=0;j<m;j++){
            cin>>s[i][j];
        }
    }
    CN c (n,m,s);
    cout<<c.codingNinja("CODINGNINJA")<<endl;

    

}