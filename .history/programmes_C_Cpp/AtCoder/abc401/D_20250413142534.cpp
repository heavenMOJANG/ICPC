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
    int cnt{};
    for (int i{}; i < n; ++ i)
        if (s[i] == 'o') {
            cnt ++;
            if (i >= 1 && s[i - 1] == '?') s[i - 1] = '.';
            if (i <= n - 2 && s[i + 1] == '?') s[i + 1] = '.';
        }
    string t = s;
    vector<pair<int, int>> val;
    for (int i{}; i < n; ++ i)
        if (s[i] == '?') {
            if (i == 0) s[i] = 'o', cnt ++;
            else if (s[i - 1] != 'o') s[i] = 'o', cnt ++;
        }
    if (cnt > k) { cout << t << "\n"; return; }
    for (int l{}; l < n; ++ l)
        if (t[l] == 'o')
            for (int r = l; r < n; ++ r)
                if (t[r] != '?') {
                    val.emplace_back(l, r - 1);
                    l = r;
                    continue;
                }
    for (auto [l, r] : val)
        if ((r - l + 1) & 1)
            for (int i = l, flag = 1; i <= r; ++ i, flag ^= 1) t[i] = (flag ? 'o' : '.');
    cout << t << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}