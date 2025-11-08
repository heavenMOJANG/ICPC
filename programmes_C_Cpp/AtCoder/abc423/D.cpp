#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n), c(n);
    queue<int> q;
    for (int i{}; i < n; ++ i) cin >> a[i] >> b[i] >> c[i], q.push(i);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int tot{}, tim{};
    while (!q.empty()) {
        while (!pq.empty() && tot + c[q.front()] > k) {
            tim = pq.top().first;
            tot -= pq.top().second;
            pq.pop();
        }
        int e = max(a[q.front()], tim);
        cout << e << "\n";
        tot += c[q.front()];
        pq.push({e + b[q.front()], c[q.front()]});
        q.pop();
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}