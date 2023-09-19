struct DSU{
    vector<int>parent,size;
    DSU(int n){
        parent = size = vector<int>(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int leader(int x){
        if(x==parent[x])return x;
        return parent[x] = leader(parent[x]);
    }
    bool samegroup(int u,int v){
        return leader(u) ==leader(v);
    }
    //merge by size
    void merge(int u,int v){
        u = leader(u);
        v = leader(v);
        if(u==v)return;
        if(size[u] >= size[v]){
            parent[v] = u;
            size[u]+=size[v];
        }else{
            parent[u] = v;
            size[v]+=size[u];
        }
    }
};
