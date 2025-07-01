#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> pre(n + 1, 0);
    for (int i{}; i < n; ++ i) pre[i + 1] = pre[i] + (s[i] == '1');
    if (pre[n] <= k) { cout << "Alice\n"; return; }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}