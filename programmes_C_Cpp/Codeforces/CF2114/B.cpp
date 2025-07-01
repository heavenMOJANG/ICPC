#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> cnt(2, 0);
    for (int i{}; i < n; ++ i) cnt[s[i] - '0'] ++;
    if (cnt[0] < n / 2 - k || cnt[1] < n / 2 - k) { cout << "NO\n"; return; }
    if ((cnt[0] - n / 2 + k) / 2 + (cnt[1] - n / 2 + k) / 2 >= k) { cout << "YES\n"; return; }
    cout << "NO\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}