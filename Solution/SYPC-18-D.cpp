#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool ok(char c){
    return c != '.';
}
int main() {
    freopen("balls.in","r",stdin);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< ll > num(m + 2), val(m + 2) ;
        vector< vector<char> > adj(n + 1, vector< char > (m + 1));
        for(int i = 1; i <= m; ++i )
            cin >> num[i];
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                cin >> adj[i][j];
        for(int i = 1; i <= m; ++i)
            cin >> val[i];
        for(int i = n; i >= 1; --i){
            vector< ll > new_val( m + 2);
            for(int j = 1; j <= m; ++j) {
                if (ok(adj[i][j]))
                    new_val[j] = max({val[j - 1], val[j], val[j + 1]});
                else new_val[j] = val[j];
            }
            val = new_val;
        }
        ll ans = 0;
        for(int i = 1; i <= m; ++i)
            ans += num[i] * val[i];
        cout << ans << '\n';

    }




}
