#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int M = 2e5 + 10;
struct Edge { int to, nxt, val; } e[M];
struct Node {
	int id, d;
	bool operator < (const Node &a) const { return d > a.d; }
};
int n, m, k, ds;
vector<pair<int, int>> g[1020];
int dis[1020], vis[1020];
void dijkstra(int s) {
	priority_queue<Node> pq;
	pq.push({s, dis[s] = 0});
}
void solve() {
	cin >> n >> m >> k >> ds;
	for (int i = 1; i <= k; ++ i) {
		string su, sv; int w;
		int u, v;
		cin >> su >> sv >> w;
		if (su[0] == 'G') {
			su.erase(0, 1);
			u = n + stoi(su);
		} else u = stoi(su);
		if (sv[0] == 'G') {
			sv.erase(0, 1);
			v = n + stoi(sv);
		} else v = stoi(sv);
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
	for (int i = 1; i <= m; ++ i) {

	}
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}