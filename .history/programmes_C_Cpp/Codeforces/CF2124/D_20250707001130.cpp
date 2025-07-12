#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct fenwick {
    int n;
    vector<int> t;
    fenwick(int _) : n(_), t(_ + 1, 0) {}
    int lowbit(int x) { return x & -x; }
    void update(int x, int d) { while (x <= n) t[x] += d, x += lowbit(x); }
    int query(int x) {
        int res{};
        while (x) {
            res += t[x];
            x -= lowbit(x);
        }
        return res;
    }
};
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    if (k == 1) { cout << "YES\n"; return; }
    fenwick ft(n);
    vector<int> cnt(n + 1, 0);
    for (int i = 1; i <= n; ++ i) ft.update(a[i], 1), cnt[a[i]] ++;
    vector<int> prev(n + 2), next(n + 2);
    for (int i{}; i <= n + 1; ++ i) prev[i] = i - 1, next[i] = i + 1;
    int l = 1, r = n, ok = 1;
    while (l < r) {
        if (a[l] == a[r]) { l = next[l], r = prev[r]; continue;}
        auto check = [&](int p) {
            int sumS = ft.query(a[p] - 1), sumE = cnt[a[p]];
        }
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}