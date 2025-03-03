#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    vector<int> a(5);
    int cnt{};
    for (int i = 0; i < 5; ++ i) cin >> a[i];
    for (int i = 0; i < 4; ++ i) if (a[i] > a[i + 1]) swap(a[i], a[i + 1]), cnt ++;
    cout << (cnt == 1 ? "Yes\n" : "No\n");
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}