#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int idx{};
    map<string, int> db;
    int Q; cin >> Q;
    while (Q --) {
        string acc; cin >> acc;
        if (db.count(acc)) cout << db[acc] << "\n";
        else { db[acc] = ++ idx; cout << db[acc] << "\n"; }
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}