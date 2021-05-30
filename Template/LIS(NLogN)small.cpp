#define itr iterator
...
typedef set<int> si;
...
si S;
for (int x : a) {
    S.insert(x);
    si::itr it = S.upper_bound(x);
    if(it != S.end()) S.erase(it);
}
/// LIS length = S.size();