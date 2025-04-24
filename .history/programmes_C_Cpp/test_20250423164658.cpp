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
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i].first;
    for (int i = 1; i <= n; ++ i) cin >> a[i].second;
    sort(a.begin() + 1, a.end());
    Fenwick ft(n);
    int tot{};
    for (int i = 1; i <= n; ++ i) {
        tot += i - 1 - ft.query(a[i].second - 1);
        ft.update(a[i].second, 1);
    }
    int ok = tot & 1;
    cout << (ok ? "A" : "B");
    for (int i = 1; i < n; ++ i) {
        string t; int l, r, d; cin >> t >> l >> r >> d;
        if ((r - l + 1) & 1) cout << (ok ? "A" : "B");
        else {
            if (d & 1) ok ^= 1;
            cout << (ok ? "A" : "B");
        }
    }
    cout << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}