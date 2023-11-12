struct DSU {
    vector<int> parent, size;

    DSU(int n) {
        parent = size = vector<int>(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int FindLeader(int i) {
        if (parent[i] == i) return i;
        return parent[i] = FindLeader(parent[i]);
    }

    bool MergeGroups(int x, int y) {
        int leader1 = FindLeader(x);
        int leader2 = FindLeader(y);
        if (leader1 == leader2) return false;
        if (size[leader1] > size[leader2]) {
            parent[leader2] = leader1;
            size[leader1] += size[leader2];
        } else {
            parent[leader1] = leader2;
            size[leader2] += size[leader1];
        }
        return true;
    }
};
