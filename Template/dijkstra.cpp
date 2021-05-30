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
const ll N = 1e5 + 7, INF = 1e18;
int n, m;
vector< vector< edge >> adj(N);
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
    return dist[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
//    freopen("portals.in", "r", stdin);
    cin >> n >> m;
    for(int i = 0, u, v, c; i < m && cin >> u >> v >> c; ++i)
        adj[u].emplace_back(v, c);
    dijkstra();

}