//change def initial value of node
const ll def = {(ll) (1e15)};
struct Node {
    ll val;

    Node(ll x = def) : val(x) {}
};

struct SparseTable {
    vector<vector<Node>> table;
    vector<int> logs;
    int n, LG;

    Node single(ll val) {
        Node ret;
        ret.val = val;
        return ret;
    }

    Node merge(Node a, Node b) {
        Node ret;
        ret.val = min(a.val, b.val);
        return ret;
    }

    void build(const vector<ll> &a) {
        n = sz(a);
        logs.resize(n + 1);
        for (int i = 2; i <= n; i++)logs[i] = logs[i >> 1] + 1;
        LG = logs[n] + 1;
        table = vector<vector<Node>>(n + 1, vector<Node>(LG));
        for (int i = 0; i < n; i++) {
            table[i][0] = single(a[i]);
        }
        for (int j = 1; j <= logs[n]; j++) {
            for (int i = 0; i <= n - (1 << j); i++) {
                table[i][j] = merge(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    Node query(int l, int r) {
        int sz = logs[r - l + 1];
        return merge(table[l][sz], table[r - (1 << sz) + 1][sz]);
    }

    Node query2(int l, int r) {
        Node cur;
        cur = single(def);
        for (int i = LG - 1; i >= 0; i--) {
            if ((1 << i) <= r - l + 1) {
                cur = merge(cur, table[l][i]);
                l += 1 << i;
            }
        }
        return cur;
    }
};
