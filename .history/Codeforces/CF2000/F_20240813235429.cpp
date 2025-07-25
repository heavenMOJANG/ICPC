#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<pii> a(n);
    int sum = 0;
    for (auto && [x, y] : a) {
        cin >> x >> y;
        if (x > y) swap(x, y);
        sum += x + y;
    }
    if (k > sum) {cout << "-1\n"; return;}
    sort(a.begin(), a.end(), [](const pii & x, const pii & y) {
        return x.first * x.second == y.first * y.second ? x.first == y.first ? x.second < y.second : x.first < y.first : x.first * x.second < y.first * y.second;
    });
    int res = 0;
    for (auto [x, y] : a) {
        if (x > 3 && y > 3) {
        } else {
            if (k >= y - 1) {
                k -= x + y;
                res += x * y;
            } else {
                res += max(0ll, k) * x;
                break;
            }
        }
    }
    cout << res << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}