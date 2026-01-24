#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/segtree>
#define int long long
using namespace std;
using namespace atcoder;
constexpr int INF = 0x7fffffff;
using S = int;
S op(S a, S b) { return a + b; }
S e() { return 0ll; }
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> p(n + 1, 0);
    for (int i = 1; i <= n; ++ i) {
        p[i] = p[i - 1];
        if (s[i - 1] == 'A') p[i] ++;
        if (s[i - 1] == 'B') p[i] --;
    }
    vector a = p;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    segtree<S, op, e> seg(a.size());
    int ans{};
    for (int i = 0; i <= n; ++ i) {
        int pos = lower_bound(a.begin(), a.end(), p[i]) - a.begin();
        ans += seg.prod(0, pos);
        seg.set(pos, seg.get(pos) + 1);
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