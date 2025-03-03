#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Node {
    int val, i, j, k;
    bool operator < (const Node & b) const {return val < b.val;}
};
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n), c(n);
    for (auto && x : a) cin >> x;
    for (auto && x : b) cin >> x;
    for (auto && x : c) cin >> x;
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    sort(c.begin(), c.end(), greater<int>());
    priority_queue<Node> pq;
    unordered_map<tuple<int, int, int>> s;
    auto add = [&](int i, int j, int k) {
        if (i < n && j < n && k < n && s.find({i, j, k}) == s.end()) {
            s.insert({i, j, k});
            pq.push({-(a[i] * b[j] + b[j] * c[k] + c[k] * a[i]), i, j, k});
        }
    };
    add(0, 0, 0);
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}