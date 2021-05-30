vector< int > prefix_function(string s) {
    int n = (int)s.length();
    vector< int > pref(n);
    for (int i = 1; i < n; i++) {
        int j = pref[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pref[j - 1];
        if (s[i] == s[j])
            j++;
        pref[i] = j;
    }
    return pref;
}
