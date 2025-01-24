#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    int sa{}, sb{};
    priority_queue<int> pqa, pqb;
    for (int i = 0; i < n; ++ i) cin >> a[i], sa += a[i], pqa.push(a[i]);
    for (int i = 0; i < m; ++ i) cin >> b[i], sb += b[i], pqb.push(b[i]);
    if (sa != sb) { cout << "NO\n"; return; }
    while (!pqa.empty() && !pqb.empty()) {
        int x = pqa.top(), y = pqb.top();
        if (x == y) pqb.pop(), pqb.pop();
        if (x < y) pqb.pop(), pqb.push((y + 1) / 2) ,pqb.push(y / 2);
        else { cout << "NO\n"; return; }
    }
    cout << (pqa.empty() && pqb.empty() ? "YES\n" : "NO\n");
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}