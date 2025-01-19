#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
 
void solve() {
	int n, m;
	cin >> n >> m;
	int cnt{}, len{}, flag = 1;
	for (int i = 0; i < n; ++ i) {
		string s;
		cin >> s;
		int siz = s.size();
		if (len + siz <= m && flag)
			len += siz, cnt ++;
		else
			flag = 0;
	}
	cout << cnt << "\n";
	return;
}
 
signed main() {
	cin.tie(0) -> sync_with_stdio(0);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
	return 0;
}