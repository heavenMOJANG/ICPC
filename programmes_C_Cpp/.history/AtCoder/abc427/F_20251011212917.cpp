#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (auto && x : a) cin >> x, x %= m;
    int nn = n / 2;
    vector<int> l(a.begin(), a.begin() + nn);
    vector<int> r(a.begin() + nn, a.end());
    map<pii, int> ml, mr;
    function<void(vector<int>&, int, int, int, int, map<pii, int>&)> dfs = [&](vector<int>& b, int x, int sum, int pre, int flag, map<pii, int>& mp) {
        if (x == nn) { mp[{sum % m, flag}]++; return; }
        dfs(b, x + 1, sum, 0, flag, mp);
        if (!pre) dfs(b, x + 2, sum + b[x], flag || !x, mp);
    };
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}