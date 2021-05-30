struct dsu {
	static const int N = 107;
	int par[N], sz[N];
 
	void init() {
		iota(par, par + N, 0);
		fill(sz, sz + N, 1);
	}
 
	int find(int u){
        return par[u] = (u == par[u] ? u : find(par[u]));
    }
    void merg(int u, int v){
        u = find(u), v = find(v);
        if(u == v)
            return;
        if(sz[u] > sz[v])
            swap(u, v);
        par[u] = v;
        sz[v] += sz[u];
    }
 
	bool conectd(int u, int v) {
		return find(u) == find(v);
	}
 
};