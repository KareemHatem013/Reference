struct DSU {
    vector<int> parent, size;
    int comp;

    DSU(int n) {
        parent = size = vector<int>(n + 1);
        comp = n;
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int Leader(int i) {
        if (parent[i] == i) return i;
        return parent[i] = Leader(parent[i]);
    }

    bool Merge(int x, int y) {
        int l1 = Leader(x);
        int l2 = Leader(y);
        if (l1 == l2) return false;
        comp--;
        if (size[l1] < size[l2])swap(l1, l2), swap(x, y);
        parent[l2] = l1;
        size[l1] += size[l2];
        return true;
    }
};
