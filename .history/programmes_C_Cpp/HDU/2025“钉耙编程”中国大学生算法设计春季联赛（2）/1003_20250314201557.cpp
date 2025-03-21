#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e6 + 10;
struct Node {
    int l, r;
    Node(int _l, int _r): l(_l), r(_r) {};
};
int n, tr[N], f0[N], a[N], rnk[N], idx, fir[N], flag[N];
int lowbit(int x) { return x & -x; }
void update(int x, int d) { while (x <= n) tr[x] += d, x += lowbit(x); }
int query(int x) {
    int res{};
    while (x) res += tr[x], x -= lowbit(x);
    return res;
}
int sum(int l, int r) { return query(r) - query(l - 1); }
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++ i) f0[i] = 0;
    fill(rnk, rnk + N, 0);
    fill(fir, fir + N, 0);
    fill(flag, flag + N, 0);
    idx = 1;
    vector<Node> vq;
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
        f0[i] += f0[i - 1];
        if (a[i] == 0) f0[i] ++;
        else {
            if (!rnk[a[i]]) rnk[a[i]] = idx ++;
            if (fir[rnk[a[i]]]) {
                if (f0[i - 1] - f0[fir[rnk[a[i]]]] && !flag[rnk[a[i]]]) {
                    vq.emplace_back(i + 1, n);
                    flag[rnk[a[i]]] = 1;
                }
            } else fir[rnk[a[i]]] = i;
        }
    }
    for (int i = 1; i <= n; ++ i) tr[i] = 0;
    map<int, int> cnt;
    int pre = 1, ans{};
    for(int i = 0; i < vq.size(); ++ i){
        for(int j = pre; j <= vq[i].r; ++ j){
            if(cnt.count(a[j])) update(cnt[a[j]], -1);
            cnt[a[j]] = j;
            update(j, 1);
        }
        pre = vq[i].r + 1;
        ans += sum(vq[i].l, vq[i].r) - (f0[vq[i].r] - f0[vq[i].l - 1]);
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