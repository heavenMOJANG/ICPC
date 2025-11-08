#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    int b = 1ll << n;
    cout << (k % b ? "1\n" : "0\n");
    vector<int> a;
    for (int i{}; i < n; ++ i) {
        vector<int> tmp;
        for (int x : a)
            tmp.emplace_back(x / 2, x - x / 2);
            a.swap(tmp);
    }
    for (int i{}; i < a.size(); ++ i) cout << a[i] << " \n"[i == a.size() - 1];
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}