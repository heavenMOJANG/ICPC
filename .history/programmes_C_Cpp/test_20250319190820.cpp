#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string s, t = "^"; getline(cin, s);
    for (auto ch : s) t += "#", t += ch;
    t += "#", t += "@";
    vector<int> p(t.size() + 1, 0);
    int r{}, mid{};
    for (int i = 1; i < t.size() - 1; ++ i) {
        p[i] = r > i ? min(p[2 * mid - i], r - i) : 1ll;
        while (t[i + p[i]] == t[i - p[i]]) p[i]++;
        if (i + p[i] > r) {
            r = i + p[i];
            mid = i;
        }
    }
    int maxn{};
    for (int i = 0; i < t.size(); ++ i) maxn = max(maxn, p[i]);
    cout << maxn - 1 << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}