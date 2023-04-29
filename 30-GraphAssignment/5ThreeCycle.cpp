/*Chapter Assignment
Problem Statement: 3 Cycle
Problem Level: MEDIUM
Problem Description:
Given a graph with N vertices (numbered from 0 to N-1) and M undirected edges, then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected by an edge.
Input Format :
The first line of input contains two space separated integers, that denotes the value of N and M.
Each of the following M lines contain two integers, that denote the vertices which have an undirected edge between them. Let us denote the two vertices with the symbol u and v.

Output Format :
Print the count the number of 3-cycles in the given graph

Constraints :
0 <= N <= 100
0 <= M <= (N*(N-1))/2
0 <= u <= N - 1
0 <= v <= N - 1
Time Limit: 1 sec

Sample Input 1:
3 3
0 1
1 2
2 0

Sample Output 1:
1
*/

#include<iostream>
using namespace std;

int main(){
    int n,m;

    cin>>n>>m;

    int** input =new int*[n];

    for(int i=0;i<n;i++){
        input[i]=new int[n];
        for(int j=0;j<n;j++){
            input[i][j]=0;
        }
    }

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        input[u][v]=1;
        input[v][u]=1;
    }
 
    int count=0;
    for(int i=0;i<n;i++){// i->j ,j->k ,k->i
        for(int j=0;j<n;j++){
            if(i==j || input[i][j]==0){
                continue;
            }
            for(int k=0;k<n;k++){
                if(j!=k && input[j][k]==1){
                    if(input[k][i]==1) count++;
                }
            }
        }
        
    }
    // count is divided by 6 because of every element of 3cycle made 2 count (clockwise and anti clockwise).
    cout<<count/6<<endl;

}