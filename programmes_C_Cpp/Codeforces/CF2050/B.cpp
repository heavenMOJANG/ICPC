#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
	int n; cin >> n;
	vector<int> a(n);
	int sum{};
	for (int i = 0; i < n; ++ i) cin >> a[i], sum += a[i];
	if (sum % n) { cout << "NO\n"; return; }
	int avg = sum / n;
	for (int i = 1; i < n - 1; ++ i) {
		int d = a[i - 1] - avg;
		a[i + 1] += d;
		a[i - 1] = avg;
	}
	for (int i = 0; i < n; ++ i) if (a[i] != avg) { cout << "NO\n"; return; }
	cout << "YES\n";
	return;
}
 
signed main() {
	cin.tie(0) -> sync_with_stdio(0);
	int _ = 1; cin >> _;
	while (_ --) solve();
	return 0;
}