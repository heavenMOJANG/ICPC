#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<pair<char, int>> a;
    a.emplace_back(s[0], 1);
    for (int i = 1; i < n; ++ i)
        if (s[i] == a.back().first) a.back().second ++;
        else a.emplace_back(s[i], 1);
    int m = a.size();
    if (m <= 1) { cout << "0\n"; return; }
    auto cal = [&](char pat) {
        vector<int> cst(m);
        for (int i{}; i < m; ++ i) {
            cst[i] = a[i].second;
            if (a[i].first == pat) cst[i] <<= 1;
        }
        vector dp(m, vector<int>(3, INF));
    };
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}