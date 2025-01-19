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
    for (auto ch : s)
        cnt[ch - 'a'] ++;
    for (int i = 0; i < 26; ++ i){
        if (!cnt[i]) continue;
        if (cnt[i] > maxn) maxn = cnt[i], maxCh = char(i + 'a');
    }
    for (int i = 25; i >= 0; -- i) {
        if (!cnt[i]) continue;
        if (cnt[i] < minn) minn = cnt[i], minCh = char(i + 'a');
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