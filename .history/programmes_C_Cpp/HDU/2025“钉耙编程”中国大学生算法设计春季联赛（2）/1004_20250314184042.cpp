#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string s, k; cin >> s >> k;
    if (k != "1") s = s + s;
    int n = s.size();
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) a[i] = s[i - 1] - 'a';
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}