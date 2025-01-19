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
    vector<int> a(n + 1, 0), b(n), t(n + 1, 0);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    function<void(int, int)> update = [&](int x, int d) {
        while (x <= n) {
            t[x] += d;
            x += lowbit(x);
        }
    };
    auto query = [&](int x) {
        int res = 0;
        while (x) {
            res += t[x];
            x -= lowbit(x);
        }
        return res;
    };
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}