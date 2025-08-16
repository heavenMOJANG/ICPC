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
    string ans{};
    vector<int> v;
    while (l <= r) {
        if (l == r) { ans += "L"; break; }
        int bl{};
        v.emplace_back(p[l]);
        if (check()) bl = 1;
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}