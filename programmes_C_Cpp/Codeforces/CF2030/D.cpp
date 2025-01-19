#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, q; cin >> n >> q;
    vector<int> p(n);
    for (int i = 0; i < n; ++ i) cin >> p[i], p[i] --;
    vector<int> pos(n);
    for (int i = 0; i < n; ++ i) pos[p[i]] = i;
    vector<int> d(n);
    for (int i = 0; i < n; ++ i) d[min(i, pos[i])] ++, d[max(i, pos[i])] --;
    for (int i = 1; i < n; ++ i) d[i] += d[i - 1];
    string s; cin >> s;
    set<int> bad;
    for (int i = 0; i < n - 1; ++ i)
        if (s[i] == 'L' && s[i + 1] == 'R' && d[i] != 0) bad.insert(i);
    while (q --) {
        int x; cin >> x;
        x --;
        if (s[x] == 'L') s[x] = 'R';
        else s[x] = 'L';
        if (s[x - 1] == 'L' && s[x] == 'R' && d[x - 1] != 0) bad.insert(x - 1);
        else bad.erase(x - 1);
        if (s[x] == 'L' && s[x + 1] == 'R' && d[x] != 0) bad.insert(x);
        else bad.erase(x);
        cout << (bad.empty() ? "YES\n" : "NO\n");
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}