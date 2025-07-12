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
};
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto && x : a) cin >> x;
    int l{}, r = n - 1;
    while (l < r && a[l] == a[r]) l ++, r --;
    if (l >= r) { cout << "YES\n"; return; }
    if (k > r - l + 1) { cout << "NO\n"; return; }
    map<int, int> mp;
    for (int i = l; i < l + k; ++ i) mp[a[i]] ++;
    for (int i = r; i > r - k; -- i) mp[a[i]] --;
    for (auto [x, y] : mp) if (y) { cout << "NO\n"; return; }
    cout << "YES\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}