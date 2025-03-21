#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
struct Node {
    int id, d;
    bool operator < (const Node & b) const { return d > b.d; }
};
vector<pair<int, int>> g[N];
int dis[N];
void dijkstra(int s) {
    priority_queue<Node> pq;
    dis
}
void solve() {
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}