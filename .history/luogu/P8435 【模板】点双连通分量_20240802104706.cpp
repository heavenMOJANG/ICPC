#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 5e5 + 10, M = 2e6 + 10;
struct Edge {int to, nxt;} e[M << 1];
int n, m, head[N], idx = 1, ans;
int dfn[N], low[N], timeStamp, cut[N], rt, cnt;
vector<int> dcc[N];
stack<int> stk;
void tarjan(int u) {
    dfn[u] = low[u] = ++ timeStamp;
    stk.push(u);
    if (u == rt && !head[u]) {
        dcc[++ cnt].emplace_back(u);
        return;
    }
    int f = 0;
    for (int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (++ f > 1 || u != rt) cut[u] = 1;
            cnt ++;
            do {
                dcc[cnt].emplace_back(stk.top());
                stk.pop();
            } while stk.
        } else low[u] = min(low[u], dfn[v]);
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    return 0;
}