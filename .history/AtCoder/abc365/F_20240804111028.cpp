#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> rec(m);
    for (auto &&[t, p] : rec) cin >> t >> p, -- p;
    vector<vector<pair<int, int>>> inOffice(n);
    {
        vector<int> in(n);
        for (const auto & [t, p] : rec)
            if (in[p]) inOffice[p].emplace_back(in[p], t), in[p] = 0;
            else in[p] = t;
    }
    constexpr int LARGE_LIMIT{1000};
    map<pii, int> memo;
    for (int )
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}