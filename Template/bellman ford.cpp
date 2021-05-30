#include <bits/stdc++.h>
using namespace std;
typedef  long long   ll;
typedef  long double ld;
typedef __int128 lx;
#define ceil(n, m) ((n / m) + ( n % m ? 1 : 0))
#define mod(n, m) (((n % m) + m) % m)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
struct edge{
    ll f, t, w;
    edge(ll f, ll t, ll w): f(f), t(t), w(w){}
    bool operator < (const  edge &e)const{
        return w > e.w;
    }
};
const ll INF = 1e18, N = 1e5 + 7;
int n, m;
vector<vector<edge>> adj(N);
vector<ll> dist(N, INF), org;
vector<bool> vis(N);
vector<int> par(N);
void print(int u){
    if(vis[u]) {
        cout << u << " ";
        return;
    }
    vis[u] = 1;
    print(par[u]);
    cout << u << " ";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
//    freopen("string.in", "r", stdin);
    cin >> n >> m;
    map<pair<int, int>, ll> cost;
    for(int i = 0, u, v, c; i < m && cin >> u >> v >> c; ++i)
        adj[u].emplace_back(u, v, c), cost[{u, v}] = c;
    bool ok = 0;
    dist[1] = 0;
    for(int i = 1; i <= 5 * n; ++i)// bellman ford with cycle finding
        for(int u = 1; u <= n; ++u)// bellman ford with n - 1 iterations only but with n iteratons to find a cycle
            for(auto v : adj[u])
                if(dist[v.t] > dist[v.f] + v.w){
                    if(i == n - 1)// save orignal dist on the (n - 1)th iteration
                        org = dist;
                   ok |= i == n;
                   dist[v.t] = dist[v.f] + v.w;
                   par[v.t] = v.f;
               }
    if(!ok)
        return cout << "NO", 0;
    int src = 0, step = n - 1;
    for(int i = 1; i <= n; ++i)
        if(dist[i] != org[i])// if dist != original dist then this node was affected by a cycle
            src = i;
    while(step--) // go  back n steps to find a node in the cycle
        src = par[src];
    cout << "YES\n";
    print(src);

}