#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (auto && x : a) cin >> x;
    int l = 1, r = *max_element(a.begin(), a.end()), ans = 1;
    auto check = [&](int x) {
        int need = (n + m + 1) / 2;
        priority_queue<int> pq;
        for (int aa : a) pq.push(aa);
        int cnt{};
        while (cnt < m) {
            int z = pq.top(); pq.pop();
            if (z < 2) { pq.push(z); break; }
            int h1 = z / 2, h2 = (z + 1) / 2;
            pq.push(h1); pq.push(h2);
            cnt ++;
        }
        int res{};
        vector<int> tmp;
        while (!pq.empty()) {
            int z = pq.top(); pq.pop();
            tmp.emplace(z);
            if (z >= x) res ++;
        }
        return res >= need;
    };
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}