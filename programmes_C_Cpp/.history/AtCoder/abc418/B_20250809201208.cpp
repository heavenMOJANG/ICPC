#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string s; cin >> s;
    int n = s.size();
    vector<int> a[26];
    for (int i{}; i < n; ++ i) a[s[i] - 'a'].emplace_back(i);
    double maxn{};
    for (int c{}; c < 26; ++ c) {
        if (g[c].size() < 2) continue;
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}