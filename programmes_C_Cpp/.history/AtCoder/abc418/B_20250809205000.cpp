#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string s; cin >> s;
    int n = s.size();
    double maxn{};
    for (int i{}; i < n - 2; ++ i)
        for (int j = i + 2; j < n; ++ j) {
            if (s[i] == s[j]) {
                double x{}, t = j - i + 1;
                for (int k = i; k <= j; ++ k) if (s[k] == s[i]) x += 1;
                maxn = max(maxn, (x - 2) / (t - 2)); 
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