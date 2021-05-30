const int N = 1e6;
int BIT[N];
void add(int idx, int val){
    while (idx < N)
        BIT[idx] += val, idx += (idx & -idx);
}
void add(int l, int r, int val){
    add(l, val), add(r + 1, -val);
}
int get(int idx){
    int sum = 0;
    while(idx > 0)
        sum += BIT[idx], idx -= (idx & -idx);
    return sum;
}
int get(int l, int r){
    return get(r) - get(l - 1);
}