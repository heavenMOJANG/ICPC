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
    function <int(int)> find = [&](int x) {
        return f[x] == x ? f[x] : f[x] = find(f[x]);
    };
    auto merge = [&](int x, int y) {
        int fx = find(x), fy = find(y);
        f[fx] = fy;
        cnt[x] ++, cnt[y] ++;
        siz[fy] += siz[fx];
    };
    for (int i = 1; i <= n; ++ i) {
        if (deg[i] != 2 || twoDeg > 5) continue;
        twoDeg ++; flag = 1;
        fill(cnt.begin() + 1, cnt.end(), 0);
        fill(siz.begin() + 1, siz.end(), 1);
        iota(f.begin() + 1, f.end(), 1);
        for (int j = 1; j < n; ++ j) {
            if (u[j] == i || v[j] == i) continue;
            merge(u[j], v[j]);
        }
        for (int j = 1; j <= n; ++ j) {
            if (j == i) continue;
            int t = find(j);
            if (cnt[j] == 1) siz[t] --;
        }
        for (int j = 1; j <= n; ++ j) {
            if (j == i) continue;
            if (find(j) == j && siz[j] > 1) flag = 0;
        }
        if (flag) break;
    }
    cout << (flag ? "Yes\n" : "No\n");
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}