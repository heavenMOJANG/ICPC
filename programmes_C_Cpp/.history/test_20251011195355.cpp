#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int gcd = exgcd(b, a % b, x, y);
    int temp = x;
    x = y;
    y = temp - (a / b) * y;
    return gcd;
}
void solve() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (auto && x : a) cin >> x;
    
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}