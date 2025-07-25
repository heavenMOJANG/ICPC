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
    int maxn{};
    for (int i = 0; i < n - 1; ++ i)
        if (a[i] == a[i + 1]) {
            map<int, int> mp;
            mp[a[i]] += 2;
            int len = 2;
            for (int j = i + 2; j < n - 1; j += 2) {
                if (a[j] == a[j + 1] && mp[a[j]] == 0) {
                    mp[a[j]] += 2;
                    len += 2;
                    maxn = max(maxn, len);
                } else {
                    i = j;
                    break;
                }
            }
        }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}