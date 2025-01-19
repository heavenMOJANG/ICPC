#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 22;
struct {
    
}
int n, m, dis[1ll << N], vis[1ll << N];
void bfs() {
    queue<int> q;
    int s = (1ll << n) - 1, tmp{};
    dis[s] = 0;
    vis[s] = 1;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = 0;
        for (int i = 1; i <= m; ++ i) {
            if ((~u) & )
        }
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    return 0;
}