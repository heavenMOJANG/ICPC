#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 3e5 + 10;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; ++ i) pre[i] = pre[i - 1] + a[i];
    vector<int> L(n + 2, 0), R(n + 2, 0);
    for (int i = 1; i <= n + 1; ++ i) L[i] = R[i - 1] + 1, R[i] = R[i - 1] + (n - i + 1);
    vector<int> prepre(n + 1, 0);
    for (int i = 1; i <= n; ++ i) prepre[i] = prepre[i - 1] + pre[i];
    vector<int> S(n + 1, 0);
    S[1] = prepre[n];
    for (int i = 2; i <= n; ++ i) S[i] = S[i - 1] + (n - i + 2) * a[i - 1];
    vector<int> preS(n + 1, 0);
    for (int i = 1; i <= n; ++ i) preS[i] = preS[i - 1] + S[i];
    auto calc = [&](int p) {
        int res = 1;
        for (int l = 1, r = n; l <= r;;) {
            
        }
    };
    auto query = [&](int pl, int pr) {

    };
    int q; cin >> q;
    while (q --) {
        int l, r; cin >> l >> r;
        cout << query(l, r) << "\n";
    }  
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}