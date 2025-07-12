#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    __int128 tot{};
    vector<pair<string, int>> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i].first >> a[i].second, tot += a[i].second;
    if (tot > 100) { cout << "Too Long\n"; return; }
    else {
        for (int i = 1; i <= n; ++ i)
            for (int j = 1; j <= a[i].second; ++ j) cout << a[i].first;
    }
    cout << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}