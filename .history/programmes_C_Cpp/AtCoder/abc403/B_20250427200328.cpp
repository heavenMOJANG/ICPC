#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string s, t; cin >> s >> t;
    int ok{};
    for (int i{}; i + t.size() - 1 < s.size(); ++ i) {
        int cnt{};
        for (int j{}; j < t.size(); ++ j) {
            if (s[i + j] == '?' || s[i + j] == t[j]) cnt ++;
        }
        if (cnt == t.size()) ok = 1;
    }
    cout << (ok ? "Yes\n" : "No\n");
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}