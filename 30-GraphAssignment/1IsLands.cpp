/*Chapter Assignment
Problem Statement: Islands
Problem Level: MEDIUM
Problem Description:
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given V islands (numbered from 1 to V) and E connections or edges between islands. Can you count the number of connected groups of islands.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.

Output Format :
Print the count the number of connected groups of islands

Constraints :
0 <= V <= 1000
0 <= E <= (V * (V-1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second

Sample Input 1:
5 8
0 1
0 4
1 2
2 0
2 4
3 0
3 2
4 3

Sample Output 1:
1

*/

#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<vector<int>> &adj,bool* visited,int u){
    if(visited[u]) return;
    visited[u]=true;
    for(int v:adj[u]){
        if(!visited[v]){
            dfs(adj,visited,v);
        }
    }
}
int isLands(vector<vector<int>> &adj,int n){
    bool* visited = new bool[n+1];
    for(int i=0;i<=n;i++){
        visited[i]=false;
    }
    int count=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(adj,visited,i);
            count++;
        }
    }
    return count;
}
int main(){
    int n,e;
    cin>>n>>e;

    vector<vector<int>> adj(n+1);

    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout<<"output"<<endl;
    cout<<isLands(adj,n)<<endl;
}