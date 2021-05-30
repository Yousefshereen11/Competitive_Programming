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
    for(int i = st - 1; i >= 0 && cur[i] != '#'; --i)
        left |= cur[i] == 'o';
    for(int i = st + 1; i < ed && cur[i] != '#'; ++i)
        midL |= cur[i] == 'o';
    for(int i = ed - 1; i > st && cur[i] != '#'; --i)
        midR |= cur[i] == 'o';
    for(int i = ed + 1; i < n && cur[i] != '#'; ++i)
        right |= cur[i] == 'o';
    int cnt = 0;
    for(int i = st + 1; i < ed && cur[i] != '#'; ++i)
        ++cnt;
    if(cnt == (ed - st) - 1) // s...o
        return false;
    if(left && (midR || right)) // os.oe or os.eo
        return false;
    if(midL && (midR || right)) // so.oe or so.eo
        return false;
    return true;
}
int solve(int i, vector< int > idx, string cur){
    if(i == idx.size()){
        if(ok(cur))
            return 0;
        return 1e9;
    }
    int p1 = solve(i + 1, idx, cur);
    cur[idx[i]] = '#';
    int p2 = 1 + solve(i + 1, idx, cur);
    return min(p1, p2);
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
        int ans = solve(0, idx, s);
        cout << (ans >= 1e9 ? -1 : ans) << '\n';

    }
}     