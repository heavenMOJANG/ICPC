#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n); int d{};
    for (auto && x: a) cin >> x,  d = __gcd(d, x);
    if (*min_element(a.begin(), a.end()) == d) { cout << n - count(a.begin(), a.end(), d) << "\n"; return; }
    
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}