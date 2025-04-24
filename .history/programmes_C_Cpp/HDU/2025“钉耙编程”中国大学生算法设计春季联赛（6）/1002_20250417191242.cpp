#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e5 + 10;
int n, x, a[N], diff[N], pre[N], st[N][20], lg2[N];
void stInit() {
    for (int i = 1; i <= n; ++i) st[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; ++j) {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}
int query(int l, int r) {
    int k = lg2[r - l + 1];
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}
bool check(int len) {
    for (int i = 1; i + len - 1 <= n; ++i) {
        int j = i + len - 1;
        int maxn = query(i, j);
        int removed = 0;
        if (i > 1) removed += diff[i - 1];
        if (i <= j - 1) removed += pre[j - 1] - pre[i - 1];
        if (j < n) removed += diff[j];
        int new_total = pre[n - 1] - removed;
        if (i > 1) new_total += abs(maxn - a[i - 1]);
        if (j < n) new_total += abs(a[j + 1] - maxn);
        if (new_total <= x) return true;
    }
    return false;
}
void solve() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    if (n == 1) { cout << "0\n"; return; }
    fill(diff, diff + n + 2, 0);
    for (int i = 1; i < n; ++i) diff[i] = abs(a[i + 1] - a[i]);
    pre[0] = 0;
    for (int i = 1; i < n; ++i) pre[i] = pre[i - 1] + diff[i];
    if (pre[n - 1] <= x) { cout << "0\n"; return; }
    stInit();
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << "\n";
}
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    lg2[1] = 0; lg2[2] = 1;
    for (int i = 3; i < N; ++i) lg2[i] = lg2[i >> 1] + 1;
    int _ = 1; cin >> _;
    while (_--) solve();
    return 0;
}