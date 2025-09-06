//undirected edges euler path 0 based
//print edgesId and nodes on the path
//https://judge.yosupo.jp/problem/eulerian_trail_undirected
const int N = 2e5+5,M = 4e6+6;
int head[N],nxt[M],to[M],ne = 0,n,oddDeg[N];
void addEdge(int u,int v){
    nxt[ne] = head[u];
    to[ne] = v;
    head[u] = ne++;
}
void addBiEdge(int u,int v){
    addEdge(u,v);
    addEdge(v,u);
}

vector<int>path,pathEdges;
int vis[M];
void euler(int u){
    for(int v,&e = head[u];~e && (v = to[e],1);){
        int ee = e;
        e = nxt[e];
        if(vis[ee])continue;
        vis[ee^1] = 1;
        euler(v);
        pathEdges.push_back(ee);
    }
    path.push_back(u);
}
int m;
void init(){
    memset(head,-1,n*sizeof head[0]);
    memset(vis,0,2*m*sizeof vis[0]);
    memset(oddDeg,0,n*sizeof oddDeg[0]);
    path.clear();
    pathEdges.clear();
    ne = 0;
}
void solve() {
    cin>>n>>m;
    init();
    int s = 0;
    for(int i = 0; i<m;i++){
        int a,b;
        cin>>a>>b;
        oddDeg[a]^=1;
        oddDeg[b]^=1;
        s = a;
        addBiEdge(a,b);
    }
    int cnt = count(oddDeg,oddDeg+n,1);
    if(cnt <= 2){// cnt is even (always two values flips)
        s = (cnt ? find(oddDeg,oddDeg+n,1) - oddDeg : s);
        euler(s);
        if(sz(path) == m+1){
            cout<<"Yes\n";
            reverse(all(path));
            for(auto&it : path)cout<<it<<' ';L;
            reverse(all(pathEdges));
            for(auto&it : pathEdges)cout<<it/2<<' ';L;
            return;
        }
    }
    cout<<"No\n";
}
