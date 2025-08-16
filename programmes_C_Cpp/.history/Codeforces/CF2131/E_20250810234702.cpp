#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto && x : a) cin >> x;
    for (auto && x : b) cin >> x;
    if (a[n - 1] != b[n - 1]) { cout << "NO\n"; return; }
    for (int i = 0; i < n - 1; ++ i)
        if (a[i] != b[i]) {
            int need = a[i] ^ b[i];
            if (a[i + 1] != need) {
                cout << "NO\n";
                return;
            }
            a[i] ^= a[i + 1]; 
        }
    cout << "YES\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}