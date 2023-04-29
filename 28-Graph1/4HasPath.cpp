/*Coding Problem
Problem Statement: Has Path 
Problem Level: MEDIUM
Problem Description:
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not. Print true or false.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)

Output Format :
true or false

Constraints :
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1

Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3

Sample Output 1 :
true

Sample Input 2 :
6 3
5 3
0 1
3 4
0 3

Sample Output 2 :
false*/

#include<iostream>
#include<queue>
using namespace std;
bool DFS(int** edges,int n,int a,int b,bool* visited){
    if(edges[a][b]==1 || a==b) return true;
    visited[a]=true;
    int ans=false;
    for(int i=0;i<n;i++){
        if(i==a) continue;
        
        if(edges[a][i]==1 && visited[i]==false){
            
           ans=ans||  DFS(edges,n,i,b,visited);
        }
    }
    return ans ;
}
bool hasPathBFS(int** edges,int n,int a,int b){
    bool*  visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    queue<int> q;
    q.push(a);
    visited[a]=true;
    while(!q.empty()){
        int curr = q.front();
        if(edges[curr][b]==1 || curr==b) return true;
        q.pop();

        for(int i=0;i<n;i++){
            if(i==curr) continue;
            if(edges[curr][i]==1 && !visited[i]){
                q.push(i);
                visited[i]=true;

            }
        }
    }
    return false;
    
}

bool hasPathDFS(int** edges,int n,int a,int b){
    bool*  visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    
    return DFS(edges,n,a,b,visited);
      
    delete [] visited;
}
int main(){
    int n,e;
    cin>> n >>e;
    int a,b;
    cin>>a>>b;
    int** edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i]= new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }

    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }

    cout<<hasPathBFS(edges,n,a,b)<<endl;
    cout<<hasPathDFS(edges,n,a,b)<<endl;
    
    
    for(int i=0;i<n;i++){
        delete [] edges[i];
    }
    delete [] edges;

}