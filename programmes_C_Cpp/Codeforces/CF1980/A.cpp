#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    vector<int> a(7, 0);
    for (auto c : s) a[c - 'A'] ++;
    int cnt = 0;
    for (auto x : a) if (x < m) cnt += m - x;
    cout << cnt << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}