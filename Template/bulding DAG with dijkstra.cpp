#include <bits/stdc++.h>
using namespace std;
typedef  long long   ll;
typedef  long double ld;
typedef __int128 lx;
#define mod(n, m) (((n % m) + m) % m)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
struct edge{
    ll to, w;
    edge(ll to = 0, ll w = 0) : to(to), w(w) {}
    bool operator <(const edge& e)const {
        return w > e.w;
    }
};
const ll N = 1e5 + 7, INF = 1e18, M = 1e9 + 7;
int n, m;
vector< vector< edge >> adj(N);
vector< vector< int >> adj2(N);
vector< int > dp(N);
vector< bool > vis(N);
ll dijkstra(int src = 1){
    vector< ll > dist(N, INF);
    priority_queue< edge > q;
    q.emplace(src, 0);
    while(q.size()){
        auto cur = q.top(); q.pop();
        if(dist[cur.to] <= cur.w)
            continue;
        dist[cur.to] = cur.w;
        for(auto v : adj[cur.to])
            if(cur.w + v.w < dist[v.to])
                q.emplace(v.to, cur.w + v.w);
    }
    for(int i = 1; i <= n; ++i) // bulding DAG
        for(auto u : adj[i])
            if(dist[i] + u.w == dist[u.to])
                adj2[i].emplace_back(u.to);
    return dist[n];
}
void dfs(int u = 1){ // dp how many ways to reach n on DAG
    vis[u] = 1;
    dp[u] = (u == n ? 1 : 0);
    for(auto v : adj2[u]) {
        if (!vis[v])
            dfs(v);
        dp[u] = (dp[u] + dp[v]) % M;
    }
}
void dfs2(int u = 1){ // dp shortest path on DAG
    vis[u] = 1;
    dp[u] = (u == n ? 1 : 1e9);
    for(auto v : adj2[u]){
        if(!vis[v])
            dfs2(v);
        if(dp[u] > dp[v] + 1)
            dp[u] = dp[v] + 1;
    }
}
void dfs3(int u = 1){ // dp longest path on DAG
    vis[u] = 1;
    dp[u] = (u == n ? 1 : -1e9);
    for(auto v : adj2[u]){
        if(!vis[v])
            dfs3(v);
        if(dp[u] < dp[v] + 1)
            dp[u] = dp[v] + 1;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
//    freopen("portals.in", "r", stdin);
    cin >> n >> m;
    for(int i = 0, u, v, c; i < m && cin >> u >> v >> c; ++i)
        adj[u].emplace_back(v, c);
    cout << dijkstra() << " ";
    dfs();
    cout << dp[1] << " ";
    fill(all(vis), 0);
    dfs2();
    cout << dp[1] - 1 << " ";
    fill(all(vis), 0);
    dfs3();
    cout << dp[1] - 1 << " ";
 
}