#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int i{}; i < n; ++ i) {
        cin >> a[i];
        if (a[i] < x) { cout << "1\n"; x = a[i]; }
        else cout << "0\n";
    } 
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}