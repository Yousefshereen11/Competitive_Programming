struct DSU {
    vector < int > par, sz;

    DSU(int n) {
        par = sz = vector < int > (n + 1, 1);
        for(int i = 1; i <= n; ++i)
            par[i] = i;
    }
    int find(int u){
        return par[u] = (u == par[u] ? u : find(par[u]));
    }
    void merge(int u, int v){
        u = find(u), v = find(v);
        if(u == v)
            return;
        if(sz[u] > sz[v])
            swap(u, v);
        par[u] = v;
        sz[v] += sz[u];
    }
    bool connected(int u, int v) {
        return find(u) == find(v);
    }
};
