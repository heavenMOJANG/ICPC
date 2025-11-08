#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; ++ i) pre[i] = (pre[i - 1] + a[i]) % 3;
    int ok{};
    for (int l = 1; l <= n - 2 && !ok; ++ l)
        for (int r = l + 1; r <= n - 1 && !ok; ++ r) {
            int s1 = pre[l], s2 = (pre[r] - pre[l] + 3) % 3, s3 = (pre[n] - pre[r] + 3) % 3;
            if (s1 == s2 && s2 == s3) {
                cout << l << " " << r << "\n";
                ok = 1;
            } else {
                if (s1 != s2 && s1 != s3 && s2 != s3) {
                    cout << l << " " << r << "\n";
                    ok = 1;
                }
            }
        }
    if (!ok) cout << "0 0\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}