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
    vector<bool> vis(n, 0);
    int l{}, r{}, ok{};
    vector<pair<int, int>> val;
    for (int i{}; i < n; ++ i)
        if (s[i] == '?') {
            if (i == 0) {
                vis[i] = 1;
                cnt ++;
                ok = 1;
            } else {
                if (!vis[i - 1]) {
                    vis[i] = 1;
                    cnt ++;
                }
                if (s[i - 1] == '?') r ++;
                else {
                    r = l = i;
                    ok = 1;
                }
            }
        } else {
            if (ok) val.emplace_back(l, r), ok = 0;
        }
    if (ok) val.emplace_back(l, r);
    cout << cnt << "\n";
    if (cnt > k) { cout << s << "\n"; return; }
    for (auto [l, r] : val)
        if ((r - l + 1) % 1) for (int i = l, flag = 1; i <= r; ++ i, flag ^= 1) s[i] = flag ? 'o' : '.';
    cout << s << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}