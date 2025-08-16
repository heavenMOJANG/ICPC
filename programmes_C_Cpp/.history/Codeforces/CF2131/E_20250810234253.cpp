#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto && x : a) cin >> x;
    for (auto && x : b) cin >> x;
    if (a[n - 1] != b[n - 1]) { cout << "NO\n"; return; }
    vector<int> need(n - 1), D;
    for (int i{}; i < n - 1; ++ i) {
        need[i] = a[i] ^ b[i];
        if (need[i] != 0) D.emplace_back(i);
    }
    if (D.empty()) { cout << "YES\n"; return; }
    vector<pair<int, int>> segs;
    int st = -1, prev = -1;
    for (int id : D) {
        if (st == -1) st = prev = id;
        else if (id == prev + 1) prev = id;
        else {
            segs.emplace_back(st, prev);
            st = prev = id;
        }
    }
    if (st != -1) segs.emplace_back(st, prev);
    for (auto [l, r] : segs) {
        vector c = a;
        vector<int> vis(r - l + 1, 0);
        deque<int> dq;
        for (int i = l; i <= r; ++ i) if (c[i + 1] == need[i]) dq.push_back(i);
        int ok{};
        while (!dq.empty()) {
            int u = dq.front(); dq.pop_front();
            if (vis[u - 1]) continue;
            c[u] ^= c[u + 1];
            vis[u - l] = 1;
            ok ++;
            if (u - 1 >= l && !vis[u - 1 - l] && c[u] == need[u - 1]) dq.push_back(u - 1);
        }
        if (ok < (r - l + 1)) { cout << "NO\n"; return; }
    }
    cout << "YES\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}