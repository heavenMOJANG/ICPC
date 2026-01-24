#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    map<int, int> mp;
    int cnt = 1000;
    while (cnt --) {
        if (n == 1) { cout << "Yes\n"; return; }
        int res = n, sum{};
        while (res) {
            int d = res % 10;
            sum += d * d;
            res /= 10;
        }
        mp[n] = 1;
        n = sum;
    }
    cout << "No\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}