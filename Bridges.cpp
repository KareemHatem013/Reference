const int N = 2e5+5;
vector<pair<int,int>>adj[N];
map<pair<int,int>,int>mp;
int dfn[N],low[N],timer;
void bridges(int node,int parent){
    dfn[node] = low[node] = ++timer;
    for(auto&[ch,x] : adj[node]){
        if(ch == parent)continue;
        if(dfn[ch] == -1){
            bridges(ch,node);
            low[node] = min(low[node],low[ch]);
            if(dfn[node] < low[ch]){
                // is_bridge
            }
        }else{
            low[node] = min(low[node],dfn[ch]);
        }
    }
}
