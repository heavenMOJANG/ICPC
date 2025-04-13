#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1e6;
void solve() {
    vector<int> f(N + 1, 0);
    for (int i = 2; i <= N; ++ i)
        if (!f[i]) for (int j = i; j <= N; j += i) f[j] ++;
    vector<int> b;
    for (int i = 2; i <= N; ++ i) if (f[i] == 2) b.emplace_back(i);
    int q; cin >> q;
    while (q --) {
        int x; cin >> x;
        cout << *prev(upper_bound(b.begin(), b.end(), x)) << "\n";
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}