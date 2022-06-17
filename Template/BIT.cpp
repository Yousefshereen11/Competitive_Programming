template< typename T, T(*combine)(T, T) >
struct fenwickTree {
    int n;
    vector< T > BIT;
    T initialValue;
    fenwickTree(int sz, T initialValue = 0) : n(sz + 5), initialValue(initialValue) {
        BIT.assign(n, initialValue);
    }

    T query(int right) {
        T ans = initialValue;
        for (; right >= 0; right = (right & (right + 1)) - 1)
            ans = combine(ans, BIT[right]);
        return ans;
    }

    T query(int left, int right) { // for +, - only
        return query(right) - query(left - 1);
    }

    void add(int idx, T delta) {
        for (; idx < n; idx = idx | (idx + 1))
            BIT[idx] = combine(BIT[idx], delta);
    }
    void add(int left, int right, T delta){
        add(left, delta);
        add(right + 1, -delta);
    }
};
