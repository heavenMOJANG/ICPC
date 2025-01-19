#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 510;
struct Edge {int to, nxt, w;}e[N * N];
int m, n, head[N], idx;
int lv[N], s, t;
bool bfs() {
    queue<int> q;
    fill(lv, lv + N, -1);
    lv[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = head[u]; i; i = e[i].nxt) {

        }
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    return 0;
}