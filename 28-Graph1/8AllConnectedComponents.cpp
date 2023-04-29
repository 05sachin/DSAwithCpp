/*Coding Problem
Problem Statement: All connected components
Problem Level: MEDIUM
Problem Description:
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.

Output Format :
Different components in new line

Constraints :
2 <= V <= 1000
1 <= E <= 1000

Sample Input 1:
4 2
0 1
2 3

Sample Output 1:
0 1 
2 3

Sample Input 2:
4 3
0 1
1 3 
0 3

Sample Output 2:
0 1 3 
2*/

#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<vector<int>>& adj,vector<bool>& visit,vector<int>& arr,int u){
    if(visit[u]==true){
        return;
    }

    visit[u]=true;
    arr.push_back(u);
    for(int v:adj[u]){
        dfs(adj,visit,arr,v);
    }

}

void print(vector<vector<int>>& ans){
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int v;
    int e;
    cin>>v>>e;
    int** edges=new int*[e];
    for(int i=0;i<e;i++){
        edges[i]=new int[2];
        cin>>edges[i][0]>>edges[i][1];

    }
    vector<vector<int>> adj(v);
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    //allConnectedComponents
   vector<vector<int>> ans;
   vector<bool> visit(v,false);

    for(int i=0;i<v;i++){
        if(visit[i]==false){
            vector<int> arr;
            dfs(adj,visit,arr,i);
            ans.push_back(arr);
        }
    }
    cout<<"output"<<endl;
    print(ans);
    


   

}