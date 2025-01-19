#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int N = 1e5 + 10;
struct {int to, nxt, w;} e[N << 1];
struct Node {
    int id, d;
    bool operator > (const Node & x) const {return d < x.d;}
};
int n, m, k, idx, head[N], dis[N], vis[N];
void addEdge(int u, int v, int w) {
    e[++ idx] = {v, head[u], w};
    head[u] = idx;
}
void dijkstra() {
    priority_queue<Node> pq;
    dis[1] = 0;
    pq.push({1,dis[1]});
    while(!)
}
void solve() {
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}