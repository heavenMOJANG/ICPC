#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    vector<int> a(4);
    a = {1, 2, 3, 4};
    do {
        int res{};
        res += a[0] * a[1] + a[2] * a[3];
        res += (a[0] + a[1]) * (a[2] + a[3]);
        cout << res << "\n";
    } while(next_permutation(a.begin(), a.end()));
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}