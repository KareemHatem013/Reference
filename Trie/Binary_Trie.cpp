class BinaryTrie {
private:
    struct Node {
        int next[2];
        int frq;

        Node() {
            memset(next, 0, sizeof next);
            frq = 0;
        }
    };

    vector<Node> v;
    int lg = 31;
public:
    BinaryTrie() {
        v.push_back(Node());
    }

    void update(ll x, int op) {
        int node = 0;
        for (int j = lg - 1; j >= 0; j--) {
            int bt = x >> j & 1;
            if (v[node].next[bt] == 0) {
                v.emplace_back();
                v[node].next[bt] = v.size() - 1;
            }
            node = v[node].next[bt];
            v[node].frq += op;
        }
    }

    ll max_xor(ll x) {
        int cur = 0;
        ll val = 0;
        for (int j = lg - 1; j >= 0; j--) {
            int bt = x >> j & 1;
            if (v[cur].next[!bt] != 0 && v[v[cur].next[!bt]].frq) {
                val |= 1ll << j;
                cur = v[cur].next[!bt];
            } else {
                cur = v[cur].next[bt];
            }
        }
        return val;
    }
};