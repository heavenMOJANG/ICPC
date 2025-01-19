#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 22;
struct {
    int b1, b2, f1, f2, w;
}a[110];
int n, m, dis[1ll << N], vis[1ll << N];
void bfs() {
    queue<int> q;
    int s = (1ll << n) - 1, v{};
    dis[s] = 0;
    vis[s] = 1;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = 0;
        for (int i = 1; i <= m; ++ i) {
            if ((~u) & a[i].b1) continue;
            if (u & a[i].b2) continue;
            v = u | a[i].f2;
            v &= ~a[i].f1;
            if (dis[v] > dis[u] + a[i].w) {
                dis[v] = dis[u] + a[i].w;
                if (!vis[v]) vis[v] = 1, q.push(v);
            }
        }
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++ i) {
        cin >> a[i].w;
        string s1, s2; cin >> s1 >> s2;
        for (int j = 0; j < n; ++ j) {
            if (s1[j] == '+') a[i].b1 += 1ll << n - j - 1;
            if (s1[j] == '-') a[i].b2 += 1ll << n - j - 1;
            if (s2[j] == '+') a[i].f2 += 1ll << n - j - 1;
            if (s2[j] == '-') a[i].f1 += 1ll << n - j - 1;
        }
    }
    return 0;
}