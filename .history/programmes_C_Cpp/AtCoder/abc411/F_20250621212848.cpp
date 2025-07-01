#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 3e5 + 10;
int U[N], V[N], fa[N], sz[N];
int findSet(int x) { return fa[x] == x ? x : fa[x] = findSet(fa[x]); }

void solve() {
    int n, m; cin >> n >> m;
    fill(sz + 1, sz + 1 + N, 1);
    atoi(fa + 1, fa + N, 1);
    vector<unordered_map<int, int>> mp(n + 1);
    for (int i = 1; i <= m; ++ i) cin >> U[i] >> V[i], mp[U[i]][V[i]] ++, mp[U[i]][V[i]] ++;

    int q; cin >> q;

    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}