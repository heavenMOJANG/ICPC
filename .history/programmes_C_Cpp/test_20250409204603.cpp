#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
	int n; cin >> n;
	for (int i{}; i < n; ++ i) cout << (rng() & 1 ? "YES\n" : "NO\n" );
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}