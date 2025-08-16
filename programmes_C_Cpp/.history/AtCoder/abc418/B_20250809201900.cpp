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
    long double maxn{};
    for (int c{}; c < 26; ++ c) {
        if (a[c].size() < 3) continue;
        for (int i{}; i < a[c].size() - 1; ++ i)
            for (int j = i + 2; j < a[c].size(); ++ j) {
                long double res = (j - i - 1) * 1.0l / (a[c][j] - a[c][i] - 1);
                maxn = max(maxn, res);
            }
    }
    cout << fixed << setprecision(17) << maxn << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}