#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string s; cin >> s;
    unordered_map<int, int> mp0, mp1;
    int n = s.size();
    int l{};
    for (int r{}; r < n; ++ r) {
        if (s[r] != s[l]) {
            if (s[l] == '0') {
                int len = r - 1 - l + 1;
            }
        }
    }
    int q; cin >> q;
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}