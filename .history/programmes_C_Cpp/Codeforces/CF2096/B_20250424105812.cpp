#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> l(n), r(n);
    sort(l.begin(), l.end(), greater<int>());
    sort(r.begin(), r.end(), greater<int>());
    int ansl = accumulate(l.begin(), l.end(), 0), ansr = accumulate(r.begin(), r.end(), 0);
    for (int i{}; i < k - 1; ++ i) ansl += r[i], ansr += l[i];
    cout << max(ansl, ansr) + 1 << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}