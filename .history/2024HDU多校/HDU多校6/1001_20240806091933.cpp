#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> u(n + 1), v(n + 1), deg(n + 1, 0), f(n + 1), siz(n + 1), cnt(n + 1);
    for (int i = 1; i < n; ++ i) {
        cin >> u[i] >> v[i];
        deg[u[i]] ++, deg[v[i]] ++;
    }
    if (n <= 2) {cout << "No\n"; return;}
    int twoDeg = 0, flag;
    for (int i = 1; i <= n; ++ i) {
        if (deg[i] != 2 || twoDeg > 5) continue;
        twoDeg ++; flag = 1;
        fill(cnt.begin() + 1, cnt.end(), 0);
        fill(siz.begin() + 1, siz.end(), 1);
        iota(f.begin() + 1, f.end(), 1);
    }

    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}