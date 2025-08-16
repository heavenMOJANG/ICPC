#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for (auto && x : p) cin >> x;
    int l{}, r = n - 1;
    deque<int> dq;
    string ans{};
    auto check = [&](int x) {
        if (dq.size() < 4) return true;
        int a = dq[dq.size() - 4];
            int b = dq[dq.size() - 3];
            int c = dq[dq.size() - 2];
            int d = dq[dq.size() - 1];
            int e = x;
            if (a < b && b < c && c < d && d < e) return false;
            if (a > b && b > c && c > d && d > e) return false;
            return true;
    };
    for (int i{}; i < n; ++ i) {
        int xl = p[l], xr = p[r];
        bool fl = check(xl), fr = check(xr);
        if (fl && (!fr || 1)) {
            ans += "L";
            if (dq.size() == 4) dq.pop_front();
            dq.push_back(xl);
            l ++;
        } else {
            ans += "R";
            if (dq.size() == 4) dq.pop_front();
            dq.push_back(xr);
            r --;
        }
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}