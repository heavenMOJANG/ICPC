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
        auto ar = a.back(); b.pop_back();
        res += ar - al;
        cnta -= 2, cntb --;
        sa.push({al, ar});
    };
    auto addb = [&] {
        assert(cntb >= 2 && cnta >= 1);
        auto bl = b.front(); b.pop_front();
        auto br = b.back(); b.pop_back();
        res += br - bl;
        cntb -= 2, cnta --;
        sb.push({bl, br});
    };
    auto dela = [&] {
        auto [al, ar] = sa.top(); sa.pop();
        res -= ar - al;
        cnta += 2, cntb ++;
    };
    auto delb = [&] {
        auto [bl, br] = sb.top(); sb.pop();
        res -= br - bl;
        cntb += 2, cnta ++;
    };
    for (int i = 0; i < kmax; ++ i) {
        if (cnta >= 2 && cntb >= 2 && a.back() - a.front() > b.back() - b.front()) adda();
        else if (cnta >= 2 && cntb >= 2 && a.back() - a.front() <= b.back() - b.front()) addb();
        else if (cntb == 0) {
            delb();
            adda();
            adda();
        } else if (cnta == 0) {
            dela();
            addb();
            addb();
        } else assert(0);
        cout << res << " ";
    }
    cout << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}