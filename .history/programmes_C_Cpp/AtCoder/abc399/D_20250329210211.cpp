#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n << 1);
    vector p(n + 1, vector<int> (2, -1));
    for (int i = 0; i < 2 * n; ++ i) {
        cin >> a[i];
        if (p[a[i]][0] == -1) p[a[i]][0] = i;
        else p[a[i]][1] = i;
    }
    int ans{};
    for (int i = 0; i < 2 * n - 1; ++ i) {
        if (a[i] == a[i + 1]) continue;
        if (p[a[i]][1] == i || p[a[i + 1]][1] == i + 1) continue;
    }
    cout << ans / 2 << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}