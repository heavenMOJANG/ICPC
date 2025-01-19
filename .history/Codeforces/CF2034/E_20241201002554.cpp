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
    if (n == 1 || k == 1) { cout << "NO\n"; return; }
    if (n <= 6 && k > fac(n)) { cout << "NO\n"; return; }
    if (k % n == 0) {
        cout << "YES\n";
        vector<int> a(n);
        iota(a.begin(), a.end(), 0);
        do {
            for (int j = 0; j < n; ++ j) {
                for (int i = 0; i < n; ++ i) cout << a[(i + j) % n] + 1 << " \n"[i == n - 1];
            }
            k -= n;
        } while (k && next_permutation(a.begin() + 1, a.end()));
        return;
    }
    if (k % 2 == 0) {
        cout << "YES\n";
        vector<int> a(n);
        iota(a.begin(), a.end(), 0);
        do {
            for (int i = 0; i < n; ++ i) cout << a[i] + 1 << " \n"[i == n - 1];
            for (int i = 0; i < n; ++ i) cout << n - a[i] << " \n"[i == n - 1];
            k -= 2;
        } while (k && next_permutation(a.begin(), a.end()));
        return;
    }
    cout << "NO\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}