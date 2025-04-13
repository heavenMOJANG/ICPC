#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n = 5;
    vector<int> a(n);
    iota(a.begin() + 1, a.end(), 1);
    multiset<int> ms;
    do {
        int cnt{};
        for (int i = 2; i < n; ++ i) for (int j = 1; j < i; ++ j) if (a[j] < a[i]) cnt ++;
        ms.insert(cnt);
    } while (next_permutation(a.begin() + 1, a.end()));
    for (auto x : ms) cout << x << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}