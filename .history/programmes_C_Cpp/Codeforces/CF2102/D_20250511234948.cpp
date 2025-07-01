#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
int tr[N];
int lowbit(int x) { return x & -x; }
void update(int x, int n) { while (x <= n) tr[x] ++ , x += lowbit(x); }
int query(int x) {
    int res{};
    while (x) res += tr[x], x -= lowbit(x);
    return res;
}
int calc(vector<int> a) {
    int n = a.size() - 1;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int m = a.size(), res{};
    vector<int> num(n + 1, 0);
    for (int i = 1; i <= n; ++ i) {
        num[i] = lower_bound(a.begin(),a.end(), num[i] ) - a.begin() + 1;
        res += query(m) - query(num[i]);
        update(num[i], m);
    }
    return res;
}
void solve() {
    int n; cin >> n;
    vector<int> o, e;
    o.emplace_back(0); e.emplace_back(0);
    for (int i{}, x; i < n; ++ i) {
        cin >> x;
        if (i & 1) e.emplace_back(x);
        else o.emplace_back(x);
    }

    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}