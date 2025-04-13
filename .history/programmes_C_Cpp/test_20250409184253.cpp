#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
	int V, E, K; cin >> V >> E >> K;
	vector g(V + 1, vector<int>(V + 1, 0));
	for (int i{}; i < E; ++ i) {
		int u, v; cin >> u >> v;
		g[v][u] = g[u][v] = 1;
	}
	int N; cin >> N;
	vector<int> clr(V + 1);
	for (int i{}; i < N; ++ i) {
		set<int> s;
		for (int j = 1; j <= V; ++ j) cin >> clr[j], s.insert(clr[j]);
		if (s.size() != K) { cout << "No\n"; continue; }
		int ok = 1;
		for (int a = 1; a <= V; ++ a) {
			for (int b = 1; b <= V; ++ b) {
				if (g[a][b] && clr[a] == clr[b]) ok = 0;
			}
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