#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Node {
    int val, i, j, k;
    bool operator > (const Node & b) const { return val < b.val; }
};
struct Tuple {
    int i, j, k;
    bool operator < (const Tuple & b) const { return i < b.i; }
};
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(n), c(n);
    for (auto && x : a) cin >> x;
    for (auto && x : b) cin >> x;
    for (auto && x : c) cin >> x;
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    sort(c.begin(), c.end(), greater<int>());
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    set<Tuple> s;
    auto add = [&](int i, int j, int k) {
        if (i < n && j < n && k < n && s.find({i, j, k}) == s.end()) {
            s.insert({i, j, k});
            pq.push({-(a[i] * b[j] + b[j] * c[k] + c[k] * a[i]), i, j, k});
        }
    };
    add(0, 0, 0);
    while (m --) {
        auto [val, i, j, k] = pq.top(); pq.pop();
        if (m == 0) cout << -val << "\n";
        add(i + 1, j, k);
        add(i, j + 1, k);
        add(i, j, k + 1);
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}