#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    vector<int> sl(n + 1), sr(n + 1), bl(n + 1), br(n + 1);
    vector<int> s, b;
    for (int i = 1; i <= n; ++ i) {
        while (s.size() && a[s.back()] > a[i]) s.pop_back();
        while (b.size() && a[b.back()] < a[i]) b.pop_back();
        sl[i] = s.size() ? s.back() : 0ll;
        bl[i] = b.size() ? b.back() : 0ll;
        s.emplace_back(i);
        b.emplace_back(i);
    }
    s.clear(); b.clear();
    for (int i = n; i; -- i) {
        while (s.size() && a[s.back()] > a[i]) s.pop_back();
        while (b.size() && a[b.back()] < a[i]) b.pop_back();
        sr[i] = s.size() ? s.back() : n + 1;
        br[i] = b.size() ? b.back() : n + 1;
        s.emplace_back(i);
        b.emplace_back(i);
    }
    vector<int> l(n + 1), r(n + 1);
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}