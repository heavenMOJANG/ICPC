#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto && x : a) cin >> x;
    int ok = 1;
    for (int i{}; i + 2 < n; ++ i) {
        int flag{}, val = -1;
        for (int j = i; j < i + 3; ++ j)
            if (a[j] != -1) {
                if (!flag) val = a[j], flag = 1;
                else if (val != a[j]) { ok = 0; break; }
            }
        if (!ok) break;
        if (flag && val == 0) { ok = 0; break; }
    }
    cout << (ok ? "YES\n" : "NO\n");
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}