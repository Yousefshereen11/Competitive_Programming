#include <bits/stdc++.h>
using namespace std;
int n, m;
string a, b;
int get(char c){
	return c - 'a';
}
string chars = "abcdefghijklmnopqrstuvwxyz";
void solve(int l, int r){
	l = max(l, 0);
	if(r == 0)
		return;
		
	string key = "";
	for(int i = l; i < r; ++i){
		int idx = get(b[i]) - get(a[i]);
		idx = ((idx % 26) + 26) % 26;
		key += chars[idx];
	}
	for(int i = l - 1, j = n - 1; i >= max(0, l - n); --i, --j)
		a[i] = key[j];
		
	solve(l - n, l);
}
int main() {
	cin >> n >> m;
	cin >> a >> b;
	a = string(m - n, ' ') + a;
	solve(m - n, m);
	cout << a;

}