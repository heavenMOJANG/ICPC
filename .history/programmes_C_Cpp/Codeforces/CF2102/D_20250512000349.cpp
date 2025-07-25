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
    fill(tr, tr + 1 + m, 0);
    for (int i = 1; i <= n; ++ i) {
        num[i] = lower_bound(a.begin(), a.end(), num[i]) - a.begin() + 1;
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
    int so = calc(o), se = calc(e);
    if (so % 2 == se % 2) {
        sort(o.begin() + 1, o.end());
        sort(e.begin() + 1, e.end());
        for (int i = 1; i <= n / 2; ++ i) cout << o[i] << " " << e[i] << " ";
        if (n & 1) cout << o[n / 2 + 1] << "\n";
        else cout << "\n";
    } else {
        vector oo = o, ee = e;
        sort(oo.begin() + 1, oo.end());
        sort(ee.begin() + 1, ee.end());
        vector<int> ans0, ans1;
        int L = INF, R = INF;
        for (int i = 1; i < o.size() - 1; ++ i)
            if (min(o[i], o[i + 1]) < min(L, R) || (min(o[i], o[i + 1]) == min(L, R) && max(o[i], o[i + 1]) < max(L, R)))
                L = o[i], R = o[i + 1];
        for (int i = 1; i < o.size() - 1; ++ i)
            if (o[i] == L && o[i + 1] == R) { swap(o[i], o[i + 1]); break; }
        L = INF, R = INF;
         for (int i = 1; i < o.size() - 1; ++ i)
            if (min(e[i], e[i + 1]) < min(L, R) || (min(e[i], e[i + 1]) == min(L, R) && max(e[i], e[i + 1]) < max(L, R)))
                L = e[i], R = e[i + 1];
        for (int i = 1; i < e.size() - 1; ++ i)
            if (e[i] == L && e[i + 1] == R) { swap(e[i], e[i + 1]); break; }
        for (int i = 1; i <= n / 2; ++ i) {
            ans0.emplace_back(o[i]);
            ans0.emplace_back(ee[i]);
            ans1.emplace_back(oo[i]);
            ans1.emplace_back(e[i]);
        }
        if (n & 1) {
            ans0.emplace_back(o[n / 2 + 1]);
            ans1.emplace_back(oo[n / 2 + 1])
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