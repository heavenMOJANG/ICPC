#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    deque<int> a(n), b(m);
    for (int i = 0; i < n; ++ i) cin >> a[i]; sort(a.begin(), a.end());
    for (int i = 0; i < m; ++ i) cin >> b[i]; sort(b.begin(), b.end());
    int kmax = min({n, m, (n + m) / 3});
    cout << kmax << "\n";
    int res{};
    stack<pair<int, int>> sa, sb;
    int cnta = n, cntb = m;
    auto adda = [&] {
        assert(cnta >= 2 && cntb >= 1);
        auto al = a.front(); a.pop_front();

    };
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}