//directed edges euler path 0 based
//print edgesId and nodes on the path
//https://judge.yosupo.jp/problem/eulerian_trail_directed
const int N = 2e5+5,M = 4e6+6;
int head[N],nxt[M],to[M],ne = 0,n,degDif[N];
void addEdge(int u,int v){
    nxt[ne] = head[u];
    to[ne] = v;
    head[u] = ne++;
}
vector<int>path,pathEdges;
void euler(int u){
    for(int v,&e = head[u];~e && (v = to[e],1);){
        int ee = e;
        e = nxt[e];
        euler(v);
        pathEdges.push_back(ee);
    }
    path.push_back(u);
}
int m;
void init(){
    memset(head,-1,n*sizeof head[0]);
    memset(degDif, 0, n * sizeof degDif[0]);
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
        degDif[a]++;
        degDif[b]--;
        s = a;
        addEdge(a,b);
    }
    int cnt = count(degDif, degDif + n, 0);
    if(cnt >= n-2){// cnt is even (always two values flips)
        if(cnt == n-2){
            s = find(degDif,degDif+n,1) - degDif;
            if(s == n){
                cout<<"No\n";
                return;
            }
        }
        euler(s);
        if(sz(path) == m+1){
            cout<<"Yes\n";
            reverse(all(path));
            for(auto&it : path)cout<<it<<' ';L;
            reverse(all(pathEdges));
            for(auto&it : pathEdges)cout<<it<<' ';L;
            return;
        }
    }
    cout<<"No\n";
}
