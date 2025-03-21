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
    map<int, int> mp;
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
        if (a[i] == 0) f0[i] ++;
        f0[i] += f0[i - 1];
    }
    for (int i = 1; i <= n; ++ i) {
        if (mp.count(a[i])) {
            
        }
        else mp[a[i]] = i;
    }
    vector<Node> vq;
    for (auto [x, v]: mp) {
        if (v.size() < 2) continue;
        for (int i = 1; i < v.size(); ++ i) {
            if (f0[v[i] - 1] - f0[v[0]] > 0 && v[i] != n) {
                vq.emplace_back(Node(v[i] + 1, n));
                break;
            }
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