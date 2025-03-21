#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Node {
    int l, r;
    Node(int _l, int _r): l(_l), r(_r) {};
};
struct FenwickTree {
    int n;
    vector<int> t;
    FenwickTree(int _n) : n(_n), t(_n + 1, 0) {}
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
    int sum(int l, int r) { return query(r) - query(l - 1); }
};
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), f0(n + 1, 0);
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
        if (a[i] == 0) f0[i] ++;
        f0[i] += f0[i - 1];
    }
    vector b = a, c = a;
    sort(b.begin() + 1, b.end());
    int len = unique(b.begin() + 1, b.end()) - b.begin() - 1;
    for (int i = 1; i <= n; ++ i) c[i] = lower_bound(b.begin() + 1, b.end(), c[i]) - b.begin() - 1;
    vector<pair<int, int>> v(len + 1, {-1, -1});
    vector<Node> vq;
    for (int i = 1; i <= n; ++ i) {
        if (v[c[i]].first == -1) v[c[i]].first = i;
        else if (v[c[i]].second == -1) {
            if (f0[i - 1] - f0[v[c[i]].first]) vq.emplace_back(i + 1, n);
        }
    }
    FenwickTree ft(n);
    map<int, int> cnt;
    int pre = 1, ans{};
    for(int i = 0; i < vq.size(); ++ i){
        for(int j = pre; j <= vq[i].r; ++ j){
            if(cnt.count(a[j])) ft.update(cnt[a[j]], -1);
            cnt[a[j]] = j;
            ft.update(j, 1);
        }
        pre = vq[i].r + 1;
        ans += ft.sum(vq[i].l, vq[i].r) - (f0[vq[i].r] - f0[vq[i].l - 1]);
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}