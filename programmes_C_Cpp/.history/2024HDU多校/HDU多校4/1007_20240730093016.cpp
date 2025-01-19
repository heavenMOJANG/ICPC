#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x & (- x))
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n), b(n), c(n);
    int sum = 0;
    for (int i = 0; i < n; ++ i) cin >> a[i], sum += a[i];
    for (int i = 0; i < n; ++ i) cin >> b[i], c[i] = b[i];
    sort(c.begin(), c.end());
    int bdr = sqrt(n);
    bdr = max(min(1ll, bdr), n);
    vector<int>s(n), t(n);
    int cs = 0, ct = 0;
    for (int i = 0; i < n; ++ i) {
        if (a[i] <= bdr) s[cs ++] = i;
        if (b[i] > bdr) t[ct ++] = i;
    }
    auto fix = [&](int & x) {
        while (x < 0) x += n;
        while (x >= n) x -= n;
    };
    auto inc = [&](int x, int y) {
        fix(x); fix(y);
        if (a[x] >= b[y]) return;
        sum += b[y] - a[x];
        a[x] = b[y];
    };
    while (q --) {
        int k; cin >> k;
        for (int i = 0; i < cs;) {
            int x = s[i];
            inc(x, x + k);
            if (a[x] > bdr) swap(s[i], s[-- cs]);
            else i ++;
        }
        for (int i = 0; i < ct; ++ i) {
            int x = t[i];
            inc(x - k, x);
        }
        cout << sum << "\n";
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}