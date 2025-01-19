#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
int a[N];
void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++ i) cin >> p[i];
    for (int i = 0; i < n; ++ i) cout << p[(i + 1) % n] << " \n"[i == n - 1];
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}