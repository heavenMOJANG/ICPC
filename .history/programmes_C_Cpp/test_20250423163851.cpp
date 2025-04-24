#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 5e5 + 10;
struct Fenwick {
    int n;
    vector<int> tr;
    Fenwick(int _) : n(_), tr(_ + 1, 0) {}
    int lowbit(int x) { return x & (-x); }
    void update(int x, int d) { while (x <= n) tr[x] += d, x += lowbit(x); }
    int query(int x) {
        int res{};
        while (x) {
            res += tr[x];
            x -= lowbit(x);
        }
        return res;
    }
};
void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (int i{}; i < n; ++ i) cin >> a[i].first;
    for (int i{}; i < n; ++ i) cin >> a[i].second;
    sort(a.begin(), a.end());
    Fenwick ft(n);
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}