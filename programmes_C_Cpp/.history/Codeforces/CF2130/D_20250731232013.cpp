#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> p[i];
    int inv{};
    {
        vector a = p;
        for (int i = 1; i < n; ++ i)
            for (int j = i + 1; j <= n; ++ j) if (a[i] > a[j]) inv ++;
    }
    int d{};
    for (int k = 1; k <= n; ++ k) {
        int pre{}, nxt{}
        for (int j = k + 1; j <= n; ++ j) if (p[j] > p[k]) nxt ++;
        for (int i = 1; i <= k - 1; ++ i) if (p[i] > p[k]) pre ++;
        
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}