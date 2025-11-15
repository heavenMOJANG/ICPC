#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    vector<int> a(3);
    for (int i = 0; i < 3; i ++) cin >> a[i];
    sort(a.begin(), a.end());
    cout << a[2] << a[1] << a[0] << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}