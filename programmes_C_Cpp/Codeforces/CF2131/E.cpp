#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int n; 
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    if (a[n - 1] != b[n - 1]) { cout << "NO\n"; return; }
    vector<int> vis(n - 1, 0);
    queue<int> q;
    auto check = [&](int i) { return !vis[i] && (a[i] ^ a[i + 1]) == b[i]; };
    for (int i = 0; i < n - 1; ++ i) if (check(i)) q.push(i);
    while (!q.empty()) {
        int i = q.front(); q.pop();
        if (vis[i]) continue;
        vis[i] = 1;
        a[i] ^= a[i + 1];
        if (i - 1 >= 0 && check(i - 1)) q.push(i - 1);
        if (i + 1 < n - 1 && check(i + 1)) q.push(i + 1);
    }
    if (a == b) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _; cin >> _;
    while (_ --) solve();
    return 0;
}
