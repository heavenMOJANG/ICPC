#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> cnt(60, 0);
    int sum = 0;
    for (int i = 0, x; i < m; ++ i) {
        cin >> x;
        cnt[(int)__lg(x)] ++;
        cout << (int)__lg(x) << "\n";
        sum += x;
    }
    if (sum < n) {cout << "-1\n"; return;}
    int ans = 0;
    for (int i = 0; i < 60; ++ i) {
        int x = (n >> i) & 1;
        cnt[i] -= x;
        if (cnt[i] >= 2) cnt[i + 1] += cnt[i] / 2;
        if (cnt[i] < 0) cnt[i + 1] --, ans ++;
    }
    cout << ans << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}