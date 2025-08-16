#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    int maxA{}, sum{};
    for (auto && x : a) cin >> x, maxA = max(maxA, x), sum += x;
    vector<int> b(q);
    int maxB{};
    for (auto && x : b) cin >> x, maxB = max(maxB, x);
    int m = max(maxA, maxB);
    vector<int> fq(m + 1, 0);
    for (int x : a) fq[x] ++;
    vector<int> prec(m + 1, 0), pres(m + 1, 0);
    int cnt{}, s{};
    for (int i{}; i <= m; ++ i) {
        cnt += fq[i];
        s += fq[i] * i;
        prec[i] = cnt;
        pres[i] = s;
    }
    for (int i{}; i < q; ++ i) {
        int B = b[i], k = B - 1, res{};
        if (k >= m) res = sum;
        else res = pres[k] + k * (n - prec[k]);
        if (res == sum) { cout << "-1\n";}
        else {
            int ans = max(B, res + 1);
            if (ans > sum) cout << "-1\n";
            else cout << ans << "\n";
        }
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}