#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<unordered_set<int>> a(m + 1);
    for (int i = 1; i <= n; ++ i) {
        int l; cin >> l;
        for (int j{}; j < l; ++ j) {
            int x; cin >> x;
            a[x].insert(i);
        }
    }
    for (int i = 1; i <= n; ++ i) {
        int ok{};
        for (int j = m; j; -- j) {
            if (a[j].size() == 1 && a[j].count(i)) { ok = 1; cout << j << "\n"; break; }
        }
        if (!ok) cout << "0\n";
        else for (int j = m; j; -- j) if (a[j].count(i)) a[j].erase(i);
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}