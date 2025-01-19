#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
bool check(int x) {
    int k = sqrt(x);
    return k * k == x;
}
void solve() {
    int n; cin >> n;
    int sum{}, cnt{};
    for (int i = 1; i <= n; ++ i) {
        int x; cin >> x;
        sum += x;
        if (check(sum)) cnt ++;
    }
    cout << cnt << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}