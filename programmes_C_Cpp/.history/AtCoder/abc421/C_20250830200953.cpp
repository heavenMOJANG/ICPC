#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int cnt1{}, cnt2{};
    vector<int> p;
    for (int i{}; i < 2 * n; ++ i)
        if (s[i] == 'A') p.emplace_back(i);
    for (int i{}; i < n; ++ i) {
        int p1 = 2 * i + 1, p2 = 2 * i + 2;
        cnt1 += abs(p[i] - p1);
        cnt2 += abs(p[i] - p2);
    }
    cout << min(cnt1, cnt2) << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}