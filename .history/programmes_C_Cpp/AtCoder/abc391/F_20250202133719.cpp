#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n), c(n);
    for (auto && x : a) cin >> x;
    for (auto && x : b) cin >> x;
    for (auto && x : c) cin >> x;
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    sort(c.begin(), c.end(), greater<int>());
    priority_queue<tuple<int, int, int, int>> pq;
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}