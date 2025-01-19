#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int fac(int x) {
    int res = 1;
    for (int i = 2; i <= x; ++ i) res *= i;
    return res;
}
void solve() {
    int n, k; cin >> n >> k;
    if (n == 1 && k == 1) { cout << "YES\n1\n"; return; }
    if (n == 1 || k == 1) { cout << "NO\n"; return; }
    if (n % 2 == 0 && k & 1) { cout << "NO\n"; return; }
    if (n <= 7 && (k > fac(n) || k + 1 == fac(n))) { cout << "NO\n"; return; }
    vector<int> p(n);
    vector<int> v1(n), v2(n);
    iota(p.begin(), p.end(), 1);
    vector<vector<int>> base;
    if (k & 1) {
        for (int i = 0; i < n; i += 2) v1[i] = n / 2 + 1 - i / 2, v2[i] = n - i / 2;
        for (int i = 1; i < n; i += 2) v1[i] = n - i / 2, v2[i] = n / 2 - i / 2;
        base = {p, v1, v2};
        for (int i = 0; i < n; ++ i) cout << p[i] << " \n"[i == n - 1];
        for (int i = 0; i < n; ++ i) cout << v1[i] << " \n"[i == n - 1];
        for (int i = 0; i < n; ++ i) cout << v2[i] << " \n"[i == n - 1];
        k -= 3;
    }
    while (k && next_permutation(p.begin(), p.end())) {
        int flag{};
        vector<int> rev(n);
        for (int i = 0; i < n; ++ i) rev[i] = n + 1 - p[i];
        for (auto & vec : base) flag |= (p == vec) | (rev == vec);
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}