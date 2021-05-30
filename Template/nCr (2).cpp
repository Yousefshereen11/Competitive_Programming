const ll N = 3e5 + 7, M = 1e9 + 7;
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
ll C(ll n, ll k){
    if(k > n)
        return 0;
    return ((fact[n] * inv[k]) % M * inv[n - k]) % M;
}
void init(){
    fact[0] = inv[0] = 1;
    for(ll i = 1; i < N; ++i){
        fact[i] = (fact[i - 1] * i) % M;
        inv[i] = power(fact[i], M - 2);
    }
}