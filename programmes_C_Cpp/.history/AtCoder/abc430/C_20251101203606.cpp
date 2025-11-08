#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s; s = " " + s;
    vector<int> pa(n + 1, 0), pb(n + 1, 0);
    for (int i = 1; i <= n; ++ i) {
        pa[i] = pa[i - 1] + (s[i] == 'a');
        pb[i] = pb[i - 1] + (s[i] == 'b');
    }
    int ans{};
    for (int l = 1; l <= n; ++ l) {
        int na = pa[l - 1] + a;
        int ia = lower_bound(pa.begin(), pa.end(), na) - pa.begin();
        if (ia > n) continue;
        int nb = pb[l - 1] + b - 1;
        int ib = upper_bound(pb.begin(), pb.end(), nb) - pb.begin() - 1;
        int r = max(l, ia);
        if (ib >= r) ans += ib - r + 1;
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}