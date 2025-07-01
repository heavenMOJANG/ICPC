#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int check(int x, int v, int w) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int cnt{};
    while (v) {
        while (!pq.empty() && pq.top() < x) pq.pop();
        if (pq.empty()) {
            pq.push(w);
            cnt ++;
        }
        auto u = pq.top(); pq.pop();
        int k = min(v, u) / x;
        v -= k * x, u -= k * x;
        pq.push(u);
    }
    return cnt;
}
void solve() {
    int v, w; cin >> v >> w;
    int maxn{};
    for (int i = 1; i <= sqrt(v); ++ i) {
        if (v % i != 0) continue;
        if (i <= w) maxn = max(maxn, check(i, v, w));
        if (i * i != v && (v / i <= w)) maxn = max(maxn, check(v / i, v, w));
    }
    cout << maxn << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}