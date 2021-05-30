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