#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string t; cin >> t;
    vector<int> cnt = {0, 0};
    int f{};
    cnt[f] ++;
    for (auto c : t) {
        if (c == '0') f ^= 1;
        cnt[f] ++;
    }
    cout << cnt[0] * (cnt[0] - 1) / 2 + cnt[1] * (cnt[1] - 1) / 2 << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}