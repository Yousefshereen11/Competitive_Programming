const ll N = 1e3 + 100, M = 1e9 + 7;
ll fact[N], inv[N];
ll power(ll x, ll p){
    ll ans = 1;
    while(p){
        if(p & 1)
            ans = ((ans % M) * (x % M)) % M;
        p >>= 1LL;
        x = ((x % M) * (x % M)) % M;
    }
    return ans;
}
ll Crep(ll n, ll k){
    return ((fact[n + k - 1] * inv[k]) % M * inv[n - 1]) % M;
}
void init(){
    fact[0] = inv[0] = 1;
    for(ll i = 1; i < N; ++i){
        fact[i] = (fact[i - 1] * i) % M;
        inv[i] = power(fact[i], M - 2);
    }
}