//https://vjudge.net/contest/636856#problem/K
vector<vector<int>> adj;
int root;
const int N = 1e5 + 5;
const int LG = 20;
int in[N], out[N], vis[N], lvl[N], frq[N], V[N], vertex[2 * N], up[N][LG];

struct MoOnTree {
    int n, timer;

    MoOnTree(int n) {//base 1
        n *= 2;
        n += 5;
        this->n = n;
        timer = 0;
        dfs(1, 0);
    }

    void dfs(int u, int p) {
        in[u] = ++timer;
        vertex[timer] = u;
        up[u][0] = p;
        for (int j = 1; j < LG; j++) {
            up[u][j] = up[up[u][j - 1]][j - 1];
        }
        for (auto &v: adj[u]) {
            if (v == p)continue;
            lvl[v] = lvl[u] + 1;
            dfs(v, u);
        }
        out[u] = ++timer;
        vertex[timer] = u;
    }

    int lca(int u, int v) {
        if (lvl[u] < lvl[v])swap(u, v);
        int k = lvl[u] - lvl[v];
        for (int j = 0; j < LG; j++) {
            if (k >> j & 1) {
                u = up[u][j];
            }
        }
        if (u == v)return u;
        for (int j = LG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }
        return up[u][0];
    }

    struct query {
        int l, r, id, lca;
        int c; //c is what we ask about
        query(int l, int r, int id, int lca, int c) : l(l), r(r), id(id), lca(lca), c(c) {}

        bool operator<(query &oth) const {
            if (l / root == oth.l / root)
                return r < oth.r;
            return l < oth.l;
        }
    };

    vector<query> ask;

    void addQuery(int u, int v, int id, int c) {
        if (in[u] > in[v])swap(u, v);
        int lc = lca(u, v);
        int l = (u == lc ? in[u] : out[u]), r = in[v];
        if (u == lc)lc = -1;
        ask.emplace_back(l, r, id, lc, c);
    }

    void add(int u) {
        vis[V[u]]++;
    }

    void remove(int u) {
        vis[V[u]]--;
    }

    void modify(int idx, int d, bool node = false) { // node = false -> idx = timer, true ->idx = node
        if (!idx)return;
        int u = (node ? idx : vertex[idx]);
        frq[u] += d;
        if (frq[u] & 1)add(u);
        else remove(u);
    }

    vector<ll> process() {
        vector<ll> ans(ask.size());
        sort(all(ask));
        int l = 0, r = -1;
        for (auto &query: ask) {
            while (r < query.r) {
                r++;
                modify(r, 1);
            }
            while (r > query.r) {
                modify(r, -1);
                r--;
            }
            while (l > query.l) {
                l--;
                modify(l, 1);
            }
            while (l < query.l) {
                modify(l, -1);
                l++;
            }
            if (~query.lca)modify(query.lca, 1, 1);
            ans[query.id] = vis[query.c];
            if (~query.lca)modify(query.lca, -1, 1);
        }
        return ans;
    }
};

int n, q;
void init() {
    for (int i = 0; i <= n; i++)in[i] = out[i] = vis[i] = lvl[i] = frq[i] = V[i] = 0;
    for (int i = 0; i <= 2 * n; i++)vertex[i] = 0;
    adj = vector<vector<int>>(n + 1);
}
void solve() {
    while (cin >> n >> q) {
        init();
        root = sqrtl(2 * n) + 1;
        for (int i = 1; i <= n; i++)cin >> V[i];
        for (int i = 1; i < n; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        MoOnTree MO(n);
        for (int id = 0; id < q; id++) {
            int a, b, c;
            cin >> a >> b >> c;
            MO.addQuery(a, b, id, c);
        }
        vector<ll> ans = MO.process();
        for (auto &it: ans)cout << (it ? "Find" : "NotFind") << endl;
        L;
    }
}
