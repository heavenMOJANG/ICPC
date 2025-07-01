#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 1e9;
void solve() {
    int q; cin >> q;
    priority_queue<int> pq0;
    priority_queue<int, vector<int>, greater<int>> pq1;
    int ans{}, z{};
    for (int i = 1; i <= q; ++ i) {
        int y; cin >> y;
        int x = ((y + z) % MOD) + 1;
        if (pq0.empty() || x <= pq0.top()) pq0.push(x), ans += x;
        else pq1.push(x);
        int siz = i + 1 >> 1;
        if (pq0.size() > siz) {
            int u = pq0.top(); pq0.pop();
            ans -= u;
            pq1.push(u);
        }
        if (pq0.size() < siz) {
            int u = pq1.top(); pq1.pop();
            ans += u;
            pq0.push(u);
        }
        z = ans;
        cout << z << "\n";
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}