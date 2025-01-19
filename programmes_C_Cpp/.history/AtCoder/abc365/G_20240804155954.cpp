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
    vector<pii> rec(m);
    for (auto && [t, p] : rec) cin >> t >> p, -- p;
    vector<vector<pii>> inOff(n);
    {
        vector<int> in(n);
        for (const auto & [t, p] : rec)
            if (in[p]) {
                inOff[p].emplace_back(in[p], t);
                in[p] = 0;
            } else in[p] = t;
    }
    constexpr int LIMIT{1000};
    map<pii, int> memo;
    for (int i{};const auto & Si : inOff) {
        if (size(Si) > LIMIT) {
            vector<int> sum(n);
            int prev_i{}, i_sum{};
            int i_inside{0};
            for (const auto & [t, p] : rec) {
                if (p == i) {
                    i_sum += i_inside * (t - prev_i);
                    prev_i = t;
                    i_inside ^= 1;
                }
                sum[p] = i_sum + i_inside * (t - prev_i) - sum[p];
            }
            for (int j = 0; j < n; ++ j) memo[minmax(i, j)] = sum[j];
        }
        ++ i;
    }
    const auto query{[& inOff, & memo](int a, int b) {
        if (memo.contains({a, b})) return memo[{a, b}];
        const auto & Sa = inOff[a];
        const auto & Sb = inOff[b];
        
    };
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}