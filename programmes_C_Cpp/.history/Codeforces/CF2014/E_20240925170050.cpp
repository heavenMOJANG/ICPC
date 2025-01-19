#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
struct edge{
    int v, w;
    edge(int v = 0, int w = 0) : v(v), w(w) {}
};
int n, m, h, a[N];
vector<edge> G[N];
int dis[N][2], f[N], g[N], inq[N][2];
void dijkstra(int s) {
    for (int i = 1; i <= n; ++ i) dis[i][0] = dis[i][1] = 1e18;
}
void solve() {
    cin >> n >> m >> h;

}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}