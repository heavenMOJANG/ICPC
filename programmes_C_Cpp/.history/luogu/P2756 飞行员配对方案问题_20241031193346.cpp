#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 110;
struct Edge {int to, nxt, w;}e[N << 4];
int n, m, head[N], idx;
void addEdge(int u, int v, int w) {e[idx] = {v, head[u], w}, head[u] = idx ++;}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> m >> n;

    return 0;
}