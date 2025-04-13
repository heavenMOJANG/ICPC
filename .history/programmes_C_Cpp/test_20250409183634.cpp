#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e4 + 10;
struct DSU {
	vector<int> fa;
	int n;
	DSU(int _) : n(_), fa(_ + 1) { iota(fa.begin(), fa.end(), 0); }
	int findSet(int x) { return fa[x] == x ? x : fa[x] = findSet(fa[x]); }
	void unionSet(int x, int y) {
		x = findSet(x), y = findSet(y);
		if (x != y) fa[x] = y;
	}
	int getFa(int x) { return fa[x]; }
};
void solve() {
	int n; cin >> n;
	DSU dsu(N);
	for (int i{}; i < n; ++ i) {
		int k, f; cin >> k >> f;
		for (int j = 1; j < k; ++ j) {
			int x; cin >> x;
			dsu.unionSet(f, x);
		}
	}
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}