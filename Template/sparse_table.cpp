const int N = 2e5 + 7, LOG = 18;
int a[N], m[N][LOG];
int n, q;
int qry(int l, int r){
    int len = r - l + 1, p = __lg(len);
    return min(m[l][p], m[r - (1 << p) + 1][p]);
}
void sparse_table(){ // min, max, gcd O(1)
    for(int i = 0; i < n; ++i)
        m[i][0] = a[i];
    for(int p = 1; p < LOG; ++p)
        for(int i = 0; i + (1 << p) - 1 < n; ++i)
            m[i][p] = min(m[i][p - 1], m[i + (1 << (p - 1))][p - 1]);
}





