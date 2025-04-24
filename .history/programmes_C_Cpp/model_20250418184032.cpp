#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string s; cin >> s;
    unordered_map<int, int> mp[2];
    int n = s.size();
    int l{};
    for (int r{}; r < n; ++ r)
        if (s[r] != s[l]) {
            if (s[l] == '0') {
                if (!mp[0].count(len)) mp[0][len] = l + 1;
                l = r;
            } else {
                if (!mp[1].count(len)) mp[1][len] = l + 1;
                l = r;
            }
        } else if (r == n - 1) {
            
        }
    int q; cin >> q;
    while (q --){
        int op, k; cin >> op >> k;
        if (!mp[op].count(k)) cout << "-1\n";
        else cout << mp[op][k] << "\n";
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}