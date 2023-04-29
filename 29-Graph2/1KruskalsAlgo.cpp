/*Coding Problem
Problem Statement: Kruskals Algorithm
Problem Level: HARD
Problem Description:
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
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
1 2 1
0 1 3
0 3 5*/

#include<iostream>
#include<algorithm>
#include "DSU.h"
using namespace std;
class Edge{
    public:
    int source;
    int dest;
    int weight;

};
bool compare(Edge e1 , Edge e2){
    return e1.weight<=e2.weight;
}
void Kruskal(Edge* input,int n,int e){
    // sort
    sort(input,input+e,compare);// E.log(E)

    int count=0;
    Edge* output = new Edge[n-1];
    DSU dsu(n);
    int i=0;
    while(count!=n-1){// E.V
        int s = input[i].source;
        int d = input[i].dest;
        int w = input[i].weight;
        int sPar = dsu.findPar(s);
        int dPar = dsu.findPar(d);

        if(sPar!=dPar) {
            dsu.unionByRank(sPar,dPar);
            output[count].source=s;
            output[count].dest=d;
            output[count].weight=w;
            count++;
           
        }
        i++;
        
    }

    // print
    cout<<"----------------"<<endl;
    for(int i=0;i<n-1;i++){
        cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
    }

}
int main(){
    int v,e;
    cin>>v>>e;

    Edge* input = new Edge[e];

    for(int i=0;i<e;i++){
        int s,d,w;
        cin>>s>>d>>w;
        input[i].source =s;
        input[i].dest=d;
        input[i].weight=w;
    }

    Kruskal(input,v,e);
    // E.log(E) + E.V
    
} 