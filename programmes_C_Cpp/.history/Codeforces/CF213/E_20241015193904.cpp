#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
using ull = unsigned long long;
constexpr int INF = 1e18;
constexpr int N = 2e5 + 10;
constexpr int BASE = 131;
struct segmentTree {
    ull val;
    int cnt;
}t[N << 4];
int a[N], b[N], pos[N], ans;
ull q[N]{1}, pre, hashVal;
void pushUp(int p) {
    t[p].cnt = t[p << 1].cnt + t[p << 1 | 1].cnt;
    t[p].val = t[p << 1].val * q[t[p << 1 | 1].cnt] + t[p << 1 | 1].val;
}
void update(int p, int pl, int pr, int pos, int k) {
    if (pl == pr) {
        if (!k) t[p].cnt --;
        else t[p].cnt ++;
        t[p].val = k;
        return;
    }
    int mid = pl + pr >> 1;
    if (pos <= mid) update(p << 1, pl, mid, pos, k);
    else update(p << 1 | 1, mid + 1, pr, pos, k);
    pushUp(p);
}
void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
        q[i] = q[i - 1] * BASE;
        pre += q[i - 1];
    }
    for (int i = 1; i <= n; ++ i) hashVal += q[n - i] * a[i];
    for (int i = 1; i <= m; ++ i) cin >> b[i], pos[b[i]] = i;
    for (int i = 1; i <= m; ++ i) {
        if (i > n) update(1, 1, m, pos[i - n], 0);
        update(1, 1, m, pos[i], i);
        int x = i - n;
        if (x < 0) continue;
        ull temp = x * pre + hashVal;
        if (t[1].val == temp) ans ++;
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}