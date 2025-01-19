#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int N = 1e6 + 10;
int n, m, idx, head[N << 1];
int low[N << 1], num[N << 1], st[N << 1], sccno[N << 1], dfn, top ,cnt;
struct {int to, nxt;} edge[N << 2];
void addEdge(int u, int v) {
    edge[++ idx] = {v, head[u]};
    head[u] = idx;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    return 0;
}