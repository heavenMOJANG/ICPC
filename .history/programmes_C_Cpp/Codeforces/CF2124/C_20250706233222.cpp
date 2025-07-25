#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto && x : a) cin >> x;
    int flag{};
    for (int i{}; i < n - 1; ++ i)
        if (a[i] > a[i + 1]) {
            int x = a[i] / __gcd(a[i], a[i + 1]);
            flag = flag == 0 ? x : __gcd(flag, x); 
        }
    cout << (flag | 1) << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}