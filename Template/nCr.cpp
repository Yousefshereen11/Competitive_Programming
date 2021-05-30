#include <bits/stdc++.h>
using namespace std;
typedef  long long   ll;
typedef  long double ld;
typedef __int128 lx;
#define ceil(n, m) ((n / m) + ( n % m ? 1 : 0))
#define mod(n, m) (((n % m) + m) % m)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
const ll M = 1e9 + 7;
vector< ll > fact(1e3 + 7, 1);
void solve(){
    for(int i = 1; i <= 1e3; ++i)
        fact[i] = fact[i - 1] * i, fact[i] %= M;
}
ll power(ll n, ll p){
    ll ans = 1;
    while(p){
        if(p & 1)
            ans = (ans * n) % M;
        n = (n * n) % M;
        p >>= 1;
    }
    return ans;
}
ll nCr(ll n, ll r){
    ll a = fact[n];
    ll b = (fact[n - r] * fact[r]) % M;
    return (a * power(b, M - 2)) % M;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    

}

