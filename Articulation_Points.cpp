//undirected
//low[i] = dfn[i] = -1
//root = false
//Articulation Points

const int N = 2e5+5;
vector<int>adj[N];
int dfn[N],low[N];
set<int>points;
int cnt;
bool root;
void dfs(int node, int parent){
    dfn[node] = low[node] = ++cnt;
    for(auto&ch : adj[node]){
        if(ch == parent)continue;
        if(dfn[ch] == -1){
            dfs(ch, node);
            low[node] = min(low[node],low[ch]);
            if(~parent){
                if(dfn[node] <= low[ch])
                    points.insert(node);
            }else {
                if(!root)root = true;
                else points.insert(node);
            }
        }else{
            low[node] = min(low[node],dfn[ch]);
        }
    }
}
