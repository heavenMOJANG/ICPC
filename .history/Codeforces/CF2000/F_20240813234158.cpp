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
        if (x == 1 && y == 1) sum += 1;
        else if (x == 1 || y == 1) sum += x * y;
        else sum += x + y;
    }
    if (k > sum) {cout << "-1\n"; return;}
    sort(a.begin(), a.end(), [](const pii & x, const pii & y) {
        return x.first == y.first ? x.second < y.second : x.first < y.first;
    });
    int res = 0;
    for (auto [x, y] : a) {
        if ()
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}