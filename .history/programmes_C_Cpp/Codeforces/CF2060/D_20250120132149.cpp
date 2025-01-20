#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++ i) cin >> a[i];
    for (int i = 0; i < n - 1; ++ i) {
        if (a[i] <= a[i + 1]) {
            int d = min(a[i], a[i + 1]);
            a[i] -= d;
            a[i + 1] -= d;
        } else {
            if (i == n - 2) { cout << "NO\n"; return; }
            else if (a[i] + a[i + 2] == a[i + 1]) {
                a[i] = a[i + 1] = a[i + 2] = 0;
            } else { cout << "NO\n"; return; }
        }
    }
    cout << "YES\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}