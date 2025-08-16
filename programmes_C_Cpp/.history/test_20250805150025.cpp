#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int id, m, k, n; cin >> id >> m >> k >> n;
    string ans(m, '0');
    for (int S{}; S < m; ++ S) {
        int ok{};
        for (int T{}; T < k; ++ T) {
            vector<int> a(n * n);
            for (int i{}; i < n * n; ++ i) cin >> a[i];
            int inv{};
            for (int i{}; i < n * n; ++ i)
                for (int j = i + 1; j < n * n; ++ j) if (a[i] > a[j]) inv ^= 1;
            if (inv & 1) ok = 1;
        }
        ans[S] = ok ? '1' : '0';
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}