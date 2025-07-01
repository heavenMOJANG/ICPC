#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, q; cin >> n >> q;
    string sv = "";
    vector<string> pc(n + 1, "");
    while (q --) {
        int p; cin >> p;
        string s;
        if (p == 1) pc[p] = sv;
        if (p == 2) {
            cin >> s;
            pc[p] += s;
        }
        if (p == 3) sv = pc[p];
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}