#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> cnt(10, 0);
    int sum = 8;
    cnt[2] = 2; cnt[0] = 3; cnt[5] = 1;
    cnt[1] = 1; cnt[3] = 1;
    int ans{};
    for (int i = 0; i < n; ++ i) {
        int x; cin >> x;
        if (cnt[x]) {
            cnt[x] --, sum --;
            if (!sum) ans = i;
        }
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}