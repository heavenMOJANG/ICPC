#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
void solve() {
    int n, l; cin >> n >> l;
    vector<string> s(n);
    vector<string> init = [&](vector<int> s) {
        vector<int> ok(n, 0);
        for (int i{}; i < n; ++ i)
            for (int j{}; j < n; ++ j) {
                if (i == j) continue;
                if (s[j].find(s[i]) != string::npos) { ok[i] = 1; break; }
            }
        vector<string> res();
        return res;
    };
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}