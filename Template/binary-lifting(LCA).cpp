#include <bits/stdc++.h>
using namespace std;
typedef  long long   ll;
typedef  long double ld;
typedef __int128 lx;
#define ceil(n, m) ((n / m) + ( n % m ? 1 : 0))
#define mod(n, m) (((n % m) + m) % m)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

const int N = 3e5 + 7;
vector<vector< pair<int, int> >> adj(N);
int anc[22][N], min_c[22][N], dep[N];

void build_anc(int u = 1, int par = 0, int d = 0, int c = 0) {
    anc[0][u] = par, min_c[0][u] = c, dep[u] = d;
    for (int p = 1; p < 22; ++p) {
        min_c[p][u] = min(min_c[p - 1][u], min_c[p - 1][anc[p - 1][u]]);
        anc[p][u] = anc[p - 1][anc[p - 1][u]];
    }
    for (auto v : adj[u])
        if (v.first != par)
            build_anc(v.first, u, d + 1, v.second);

}
int kth_anc(int u, int k){// go up from u kth steps
    for(int p = 0; p < 22; ++p)
        if((k >> p) & 1)
            u = anc[p][u];
    return u;
}
int kth_min(int u, int k){// go up from u kth steps while minimizing
    int c = 1e9;
    for(int p = 0; p < 22; ++p)
        if((k >> p) & 1)
            c = min(c, min_c[p][u]), u = anc[p][u];
    return c;
}
int lca(int u, int v){
    if(dep[u] > dep[v])
        swap(u, v);
    v = kth_anc(v, dep[v] - dep[u]); // make u and v on the same level
    if(v == u)
        return u;
    for(int p = 21; p >= 0; --p)
        if(anc[p][u] != anc[p][v])
            u = anc[p][u], v = anc[p][v];
    return anc[0][u];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
//    freopen("dream.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    for(int i = 0, u, v, c; i < m && cin >> u >> v >> c; ++i)
        adj[u].emplace_back(v, c), adj[v].emplace_back(u, c);
    build_anc();
    int q;
    cin >> q;
    for(int u, v; q-- && cin >> u >> v; ){
        int l = lca(u, v);
        cout << min(kth_min(u, dep[u] - dep[l]), kth_min(v, dep[v] - dep[l])) << '\n';
    }



}