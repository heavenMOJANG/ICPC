#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    set<int> s;
    for (int i{}; i < n; ++ i) {
        cin >> a[i];
        if (a[i] != -1) s.insert(a[i]);
    }
    if (s.count(0)) { cout << "NO\n"; return; }
    if (s.size() > 1) { cout << "NO\n"; return; }
    cout << "YES\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}