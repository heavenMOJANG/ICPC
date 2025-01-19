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
        return x.first == y.first ? x.second < y.second : x.first < y.first;
    });
    int res = 0;
    for (auto [x, y] : a) {
        if (x > 2 && y > 2) {
            if (k > y + 1) {
                k -= x + y;
                res += x * y;
            } else {
                if (k == 1) {
                    res += x;
                    break;
                } else if (k == 2) {
                    res += min(x + y - 1, 2 * x);
                    break;
                } else if (k == 3) {
                    res += min(x + 2 * (y - 1), 3 * x);
                    break;
                } else if (k == 4) {
                    res += min(2 * (x + y - 2), 4 * x);
                    break;
                } else {
                    int tmp = k - 4;
                    res += min({x * y, 2 * (x + y - 2) + n * (x - 2), n * x});
                    break;
                }
            }
        } else {
            if (k > y - 1) {
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