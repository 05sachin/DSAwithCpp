#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

vector<int>  pathBFS(int** edges,int n,int a,int b){
    bool*  visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    vector<int> ans;
    unordered_map<int,int> mp;
    queue<int> q;
    q.push(a);
    visited[a]=true;
    while(!q.empty()){
        int curr = q.front();
        if(curr==b) {
            
            while(curr!=a){
                ans.push_back(curr);
                
                int temp=mp[curr];
                mp.erase(curr);
                curr = temp;
            }
            ans.push_back(curr);
        }
        q.pop();

        for(int i=0;i<n;i++){
            if(i==curr) continue;
            if(edges[curr][i]==1 && !visited[i]){
                mp.insert({i,curr});
                q.push(i);
                visited[i]=true;

            }
        }
    }
    return ans;
    
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

    vector<int> ans = pathBFS(edges,n,a,b);
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<" ";
    }
    
    
    for(int i=0;i<n;i++){
        delete [] edges[i];
    }
    delete [] edges;

}