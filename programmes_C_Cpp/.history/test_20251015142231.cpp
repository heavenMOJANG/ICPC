#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
	vector<int> a(13);
	iota(a.begin(), a.end(), 1);
	shuffle(a.begin(), a.end(), rng);
	for (auto x : a) cout << x << ' ';
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}