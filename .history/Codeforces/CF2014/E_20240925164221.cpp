#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
int n, m, h;
int dis[2][N], disl[N], disr[N], horse[N];
vector<pii> g[N];
void dijkstra() {
    memset(dis, 63, sizeof(dis));
    dis[0][1] = 0;
    priority_queue<pii> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        d *= -1;
        if (d > dis[0][u]) continue;
        disl[u] = d;
        if (horse[u]) dis[1][u] = d;
        for (auto [v, w] : g[u]) {
            w += d;
        }
    }
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