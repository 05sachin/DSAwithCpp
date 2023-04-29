/*Coding Problem
Problem Statement: Prim's Algorithm
Problem Level: HARD
Problem Description:
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format -
v1 v2 w

where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)

Output Format :
MST

Constraints :
2 <= V, E <= 10^5

Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8

Sample Output 1 :
0 1 3
1 2 1
0 3 5*/

#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int findMin(vector<int>& weight,vector<bool>& visit,int n){

    int v=-1;
    for(int i=0;i<n;i++){
        if(!visit[i] && (v==-1 || weight[v]>weight[i])){
            v=i;
        }
    }
    return v;
}
int main(){
    int n;
    int e;
    cin>>n>>e;

    vector<vector<pair<int,int>>> adj(n);

    for(int i=0;i<e;i++){
        int u;
        int v ;
        int w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    vector<int> weight(n,INT_MAX);
    weight[0]=0;
    vector<bool> visit(n,false);
    vector<int> parents(n,-1);
    
    for(int i=0;i<n-1;i++){
        int u = findMin(weight,visit,n);
        visit[u]=true;
        
        for(pair<int,int> &x:adj[u]){
            int v = x.first;
            int w = x.second;
            
            if(visit[v]==false && weight[v]>w){
                weight[v]=w;
                parents[v]=u;
            }
        }
    }
    cout<<"--------------------"<<endl;
    for(int i=1;i<n;i++){
        if(parents[i]<i){
            cout<<parents[i]<<" "<<i<<" "<<weight[i]<<endl;
        }else{
            cout<<i<<" "<<parents[i]<<" "<<weight[i]<<endl;
        }
        
    }




}