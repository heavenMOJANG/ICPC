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
    vector<int> a(n);
    for (auto && x : a) cin >> x;
    if (k == 1) { cout << "YES\n"; return; }
    vector b = a;
    sort(b.begin(), b.end());
    int x = b[k - 2];
    vector<int> c;
    for (int i{}; i < n; ++ i) if (a[i] <= x) c.emplace_back(a[i]);
    int cnt = c.size() - k + 1;
    int l{}, r = c.size() - 1;
    while (l < r) {
        if (c[l] != c[r]) {
            if (!cnt) { cout << "NO\n"; return; }
            if (c[l] == x) l ++, cnt --;
            else if(c[r] == x) r --, cnt --;
            else { cout << "NO\n"; return; }
        } else l ++, r --;
    }
    cout << "YES\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}