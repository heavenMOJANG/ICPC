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
struct {int to, nxt;} e[N << 2];
void addEdge(int u, int v) {
    e[++ idx] = {v, head[u]};
    head[u] = idx;
}
void tarjan(int u) {
    st[top ++] = u;
    low[u] = num[u] = ++dfn;
    for (int i = head[u]; i; i =e[i].nxt) {
        int v = e[i].to;
        if (!num[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (!sccno[v]) low[u] = min(low[u], num[v]);
    }
    if (low[u] == num[u]) {
        cnt ++;
        while(1) {
            int v = st[-- top];
            sccno[v] = cnt;
            if (u == v) break;
        }
    }
}
int twoSat() {
    for (int i = 1; i <= 2 * n; ++ i)
        if (!num[i]) tarjan(i);
    for (int i = 1; i <= n; ++ i)
        if (sccno[i] == sccno[i + n]) return 0;
    return 1;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m;
    while (m --) {
        int a, va, b, vb;
        cin >> a >> va >> b >> vb;
        int na = va ^ 1, nb = vb ^ 1;
        addEdge(a + na * n, b + vb * n);
        addEdge(b + nb * n, a + va * n);
    }
    if (twoSat()) {
        cout << "POSSIBLE\n";
        for (int i = 1; i <= n; ++ i) cout << (sccno[i] > sccno[i + n]) << " \n"[i == n];
    } else cout << "IMPOSSIBLE\n";
    return 0;
}