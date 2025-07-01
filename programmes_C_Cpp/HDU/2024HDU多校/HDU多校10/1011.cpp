#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n), b(n);
    int cnt = 0;
    for (auto && x : a) {
        cin >> x;
        cnt += x - 1;
    }
    for (auto && x : b) cin >> x;
    cnt = min(cnt, m - 1);
    cout << (cnt < k ? "YES\n" : "NO\n");
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}