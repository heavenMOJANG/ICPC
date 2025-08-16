#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    multiset<int> a;
    for (int i{}; i < n; ++ i) {
        int x; cin >> x;
        a.insert(x);
    }
    for (int i{}; i < m; ++ i) {
        int x; cin >> x;
        if (a.find(x)) a.extract(x);
    }
    for (auto x : a) cout << x << " ";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}