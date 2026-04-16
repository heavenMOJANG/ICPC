#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, t; cin >> n >> t;
    vector<int> a(n);
    for (auto && x : a) cin >> x;
    int f = 1, tim{}, nxt = -1, ans{};
    int i{};
    while (i < n) {
        if (!f) {
            if (nxt <= a[i] && nxt < t) f = 1, tim = nxt;
            else { i++; continue; }
        }
        if (a[i] < t) {
            ans += a[i] - tim;
            f = 0;
            nxt = a[i] + 100;
        }
        i ++;
    }
    if (f && tim < t) ans += t - tim;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}