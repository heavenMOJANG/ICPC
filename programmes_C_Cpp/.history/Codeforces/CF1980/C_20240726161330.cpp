#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++ i) cin >> a[i];
    map<int, int> mpb, mpd;
    for (int i = 0; i < n; ++ i) {
        cin >> b[i];
        if (a[i] != b[i]) mpb[b[i]] ++;
    }
    int m; cin >> m;
    vector<int> d(m);
    for (int i = 0; i < m; ++ i) {
        cin >> d[i];
        mpd[d[i]] ++;
    }
    int flag = 0;
    for (int i = 0; i < n; ++ i)
        if (b[i] == d[m - 1]) {flag = 1; break;}
    if (!flag) {cout << "NO\n"; return;}
    for (auto [x, y] : mpb)
        if (mpd[x] < y) {
            cout << "NO\n";
            return;
        }
    cout << "YES\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}