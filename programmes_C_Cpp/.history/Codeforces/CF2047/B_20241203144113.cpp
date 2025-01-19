#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> cnt(26, 0);
    int maxn{}, minn = 20;
    char maxCh, minCh;
    for (auto ch : s) {
        cnt[ch - 'a'] ++;
        if (cnt[ch - 'a'] > maxn) maxn = cnt[ch - 'a'], maxCh = ch;
        if (cnt[ch - 'a'] < minn) minn = cnt[ch - 'a'], minCh = ch;
    }
    if (maxn == n) { cout << s << "\n"; return; }
    for (int i = 0; i < n; ++ i)
        if (s[i] == minCh) { s[i] = maxCh; break; }
    cout << s << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}