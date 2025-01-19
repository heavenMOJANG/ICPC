#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
int n, m;
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m;
    vector<int> d(n + 2, 0);
    for (int  i = 1, u, v; i <= m; ++ i) {
        cin >> u >> v;
        if (u > v) swap(u, v);
        d[u] ++;
        d[v] --;
    }
    for (int i = 1; i <= n; ++ i) d[i] += d[i - 1];
    for (int i = 1; i <= n; ++ i) cout << d[i] << " ";
    return 0;
}