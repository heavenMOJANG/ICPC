#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
class FenwickTree {
public:
    int n;
    vector<int> tree;
    FenwickTree(int _n) : n(_n), tree(_n + 10, 0) {}
    void modify(int x, int d) { while (x <= n) tree[x] += d, x += lowbit(x); }
    int query(int x) { int res{}; while (x) res += tree[x], x -= lowbit(x); return res; }
private:
    int lowbit(int x) { return x & (-x); }
};
int n, m, a[N], pre[N], sum, ans;
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m;
    FenwickTree ft(m);
    for (int i = 1; i <= n; ++ i) cin >> a[i], pre[i] = (pre[i - 1] + a[i]) % m;
    for (int i = 1; i <= n; ++ i) {
        ans += pre[i] * i - sum + (ft.query(m - 1) - ft.query(pre[i])) * m;
        sum += pre[i];
        ft.modify(pre[i], 1); 
    }
    cout << ans << "\n";
    return 0;
}