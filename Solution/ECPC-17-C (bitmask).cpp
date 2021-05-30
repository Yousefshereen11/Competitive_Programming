#include <bits/stdc++.h>
using namespace std;
typedef  long long   ll;
typedef  long double ld;
typedef __int128 lx;
#define mod(n, m) (((n % m) + m) % m)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
int n;
string s;
int st = -1, ed = -1;
void get(){
    for(int i = 0; i < n; ++i){
        if(s[i] == 's')
            st = i;
        if(s[i] == 'e')
            ed = i;
    }
}
bool ok(string cur){
    bool left = 0, midL = 0, midR = 0, right = 0;
    int cnt = 0;
    for(int i = st - 1; i >= 0 && cur[i] != '#'; --i)
        left |= cur[i] == 'o';
    for(int i = st + 1; i < ed && cur[i] != '#'; ++i)
        midL |= cur[i] == 'o', ++cnt;
    for(int i = ed - 1; i > st && cur[i] != '#'; --i)
        midR |= cur[i] == 'o';
    for(int i = ed + 1; i < n && cur[i] != '#'; ++i)
        right |= cur[i] == 'o';

    if(cnt == (ed - st) - 1) // s...o
        return false;
    if(left && (midR || right)) // os.oe or os.eo
        return false;
    if(midL && (midR || right)) // so.oe or so.eo
        return false;
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("portals.in", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> s;
        get();
        if(st > ed)
            reverse(all(s)), get();
        vector< int > idx;
        for(auto i : {st - 1, st + 1, ed - 1, ed + 1})
            if(i >= 0 && i < n && s[i] == '.')
                idx.emplace_back(i);
        int ans = -1;
        for(int i = 0; i < (1 << (idx.size())); ++i){
            for(int j = 0; j < idx.size(); ++j)
                (i >> j) & 1 ? s[idx[j]] = '#' : s[idx[j]] = '.';
            int cur = __builtin_popcount(i);
            if(ok(s))
                ans = (ans == -1 ? cur : min(ans, cur));
        }
        cout << ans << '\n';

    }
}     