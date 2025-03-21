#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() { 
    int n; cin >> n;
    vector<int> a(n);
    for (auto && x : a) cin >> x;
    int l = n - 1, r = n - 1, maxn{};
    for (int i = n - 2; ~i; -- i) {
        int Min{}, Max{}, res{};
        for (int j = i + 1; j < n; ++ j) {
            if (a[j] > a[i]) Max ++;
            if (a[j] < a[i]) Min ++;
            res = Min - Max;
            if (res > maxn) l = i, r = j, maxn = res;
        }
    }
    cout << l + 1 << " " << r + 1 << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}