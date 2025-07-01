#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int h, w, n; cin >> h >> w >> n;
    unordered_set<int> r[h + 1], c[w + 1];
    for (int i{}; i < n; ++ i) {
        int x, y; cin >> x >> y;
        c[y].insert(x);
        r[x].insert(y);
    }
    vector<int> vr(h + 1, 0), vc(w + 1, 0);
    int q; cin >> q;
    while (q --) {
        int op, p; cin >> op >> p;
        if (op == 1) {
            if (vr[p]) { cout << "0\n"; continue; }
            cout << r[p].size() << "\n";
            for (auto y: r[p]) c[y].erase(p);
            r[p].clear();
            vr[p] = 1;
        } else {
            if (vc[p]) { cout << "0\n"; continue; }
            cout << c[p].size() << "\n";
            for (auto x: c[p]) r[x].erase(p);
            c[p].clear();
            vc[p] = 1;
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