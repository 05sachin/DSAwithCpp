#include<iostream>
#include<queue>
using namespace std;
void printBFS(int** edges,int n,int s){
    bool*  visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    queue<int> q;
    q.push(s);
    visited[s]=true;
    while(!q.empty()){
        int sv = q.front();
        cout<<sv<<" ";
        q.pop();

        for(int i=0;i<n;i++){
            if(i==sv) continue;
            if(edges[sv][i]==1 && !visited[i]){
                q.push(i);
                visited[i]=true;

            }
        }
    }
    delete [] visited;
}
int main(){
    int n,e;
    cin>> n >>e;

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

    
    printBFS(edges,n,0);


    for(int i=0;i<n;i++){
        delete [] edges[i];
    }
    delete [] edges;

}