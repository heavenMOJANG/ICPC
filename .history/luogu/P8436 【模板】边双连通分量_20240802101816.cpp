#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 5e5 + 10, M = 2e6 + 10;
struct Edge {int to, nxt;}e[M << 1];
int n, m, ans, idx = 1, head[N];
int timeStamp, dfn[N], low[N], vis[N];
vector<vector<int>> bcc;
void addEdge(int u, int v) {e[++ idx] = {v, head[u]}; head[u] = idx;}
void tarjan(int u, int f) {
	dfn[u] = low[u] = ++ timeStamp;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    return 0;
}