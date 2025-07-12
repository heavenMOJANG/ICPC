#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto && x : a) cin >> x;
    for (int i{}; i < n; ++ i)
        for (int j = i + 1; j < n; ++ j)
            if (a[i] > a[j]) {
                cout << "YES\n2\n" << a[i] << " " << a[j] << "\n";
                return;
            }
    cout << "NO\n"; 
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}