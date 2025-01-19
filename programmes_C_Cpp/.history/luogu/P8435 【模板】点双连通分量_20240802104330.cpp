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
int dfn[N], low[N], timeStamp, cut[N], rt;
vector<int> dcc[N];
stack<int> stk;
void tarjan(int u, int f) {

}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    return 0;
}