/*Coding Problem
Problem Statement: Dijkstra's Algorithm
Problem Level: HARD
Problem Description:
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Print the ith vertex number and the distance from source in one line separated by space. Print different vertices in different lines.
Note : Order of vertices in output doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)

Output Format :
In different lines, ith vertex number and its distance from source (separated by space)

Constraints :
2 <= V, E <= 10^5

Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8

Sample Output 1 :
0 0
1 3
2 4
3 5*/

#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int findMin(bool* visited,int* dist,int n){
    int v=-1;

    for(int i=0;i<n;i++){
        if(!visited[i] && (v==-1 || dist[v]>dist[i])){
            v=i;
        }
    }
    return v;

}
void dijkstra(vector<vector<pair<int,int>>> &adj,int n,int e){
    bool* visited = new bool[n];
    int* dist = new int[n];
    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
        visited[i]=false;
    }
    dist[0]=0;

    for(int i=0;i<n;i++){
        int u = findMin(visited,dist,n);
        visited[u]=true;

        for(pair<int,int> &x:adj[u]){
            int v = x.first;
            int w =x.second;
            if(!visited[v] && dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;   
            }
        }
    }

    // print
    cout<<"-----------------------------"<<endl;
    for(int i=0;i<n;i++){
        cout<<i<<" "<<dist[i]<<endl;
    }

}
int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<pair<int,int>>> adj(n);

    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});

    }
    dijkstra(adj,n,e);


}