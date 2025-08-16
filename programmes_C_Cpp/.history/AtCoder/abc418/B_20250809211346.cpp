#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string s; cin >> s;
    int n = s.size();
    double maxn{};
    for (char c : s) {
        vector<int> p;
        for (int i{}; i < n; ++ i) if (s[i] == c) p.emplace_back(i);
        int m = p.size();
        if (m < 3) continue;
        for (int i{}; i < m - 2; ++ i)
            for (int j = i + 2; j < m; ++ j) {
                double x = j - i + 1, t = p[j] - p[i] + 1;
                double r = (x - 2) / (t - 2);
                maxn = max(maxn, r);
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