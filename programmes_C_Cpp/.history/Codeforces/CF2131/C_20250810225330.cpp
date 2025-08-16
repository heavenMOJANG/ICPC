#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> S(n), T(n);
    map<pair<int, int>, int> ms, mt;
    for (auto && x : S) {
        cin >> x;
        int r = x % k, rr = k - r;
        if (r > rr) swap(r, rr);
        ms[{r, rr}] ++;
    }
    for (auto && x : T) {
        cin >> x;
        int r = x % k, rr = k - r;
        if (r > rr) swap(r, rr);
        mt[{r, rr}] ++;
    }
    for (auto [p, v] : mt) if (ms[p] != v) { cout << "NO\n"; return; }
    cout << "YES\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}