class DSU{
    int* parent;
    int* rank;
    int* size;
    
    public:
    DSU(int v){
        parent = new int[v];
        rank = new int[v];
        size = new int[v];
        for(int i=0;i<v;i++){
            parent[i]=i;
            rank[i]=0;
            size[i]=1;
        }

    }
    
    int findPar(int u){
        if(u==parent[u]){
            return u;
        }
        return parent[u]=findPar(parent[u]);
    }

    void unionByRank(int u,int v){
        int uPar = findPar(u);
        int vPar = findPar(v);
        if(uPar==vPar) return ;

        if(rank[uPar]==rank[vPar]){
            parent[vPar]=uPar;
            rank[uPar]++;
        }else if(rank[uPar]>rank[vPar]){
            parent[vPar]=uPar;
        }else{
            parent[uPar]=vPar;
        }
    }
     void unionBySize(int u,int v){
        int uPar = findPar(u);
        int vPar = findPar(v);
        if(uPar==vPar) return ;

        if(size[uPar]>=size[vPar]){
            parent[vPar]=uPar;
            size[uPar]=size[uPar]+size[vPar];
        }else{
            parent[uPar]=vPar;
            size[vPar]=size[vPar]+size[uPar];
        }
    }

};