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
    int ok = 1;
    for (auto [l, r] : segs) {
        int len = r - l + 1;
        vector<int> c(len + 1);
        for (int i{}; i <= len; ++ i) c[i] = a[l + i];
        vector<int> vis(len, 0);
        deque<int> dq;
        for (int i{}; i < len; ++ i) if (c[i + 1] == need[l + i]) dq.push_back(i);
        int done{};
        while (!dq.empty()) {
            int u = dq.front(); dq.pop_front();
            if (vis[u]) continue;
            vis[u] = 1;
            c[u] ^= c[u + 1];
            done ++;
            if (u >= l && !vis[u - 1] && c[u] == need[l + u - 1]) dq.push_back(u - 1);
        }
        if (done < len) { ok = 0; break; }
    }
    cout << (ok ? "YES\n" : "NO\n");
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}