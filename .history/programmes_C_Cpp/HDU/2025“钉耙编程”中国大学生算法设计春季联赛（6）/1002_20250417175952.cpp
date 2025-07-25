#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e5 + 10;
int n, x, a[N], diff[N], st[N][20], lg2[N];
void stInit() {
    for (int i = 1; i <= n; ++ i) st[i][0] = a[i];
    for (int j = 1; j <= lg2[n]; ++ j)
        for (int i = 1; i + (1 << j) < n; ++ i)
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]); 
}
int query(int l, int r) {
    int k = lg2[r - l + 1];
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}
bool check(int len) {
    for (int i = 1; i + len - 1 <= n; ++ i) {
        int res = diff[i - 1] + diff[n + 1] - diff[i + len];
        int maxn = query(i, i + len - 1);
        if (i > 1) res += abs(query(i, i + len - 1) - a[i - 1]);
        if (i + len - 1 < n) res += abs(a[i + len] - query(i, i + len))
        if (res <= x) return 1; 
    }
    return 0;
}
void solve() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    if (n == 1) { cout << "0\n"; return; }
    for (int i = 2; i <= n; ++ i) diff[i] = abs(a[i + 1] - a[i]);
    for (int i = 2; i <= n + 1; ++ i) diff[i] += diff[i - 1];
    if (diff[n - 1] <= x) { cout << "0\n"; return; }
    stInit();
    int l = 1, r = n;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    lg2[1] = 0; lg2[2] = 1;
    for (int i = 3; i < N; ++ i) lg2[i] = lg2[i / 2] + 1;
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}