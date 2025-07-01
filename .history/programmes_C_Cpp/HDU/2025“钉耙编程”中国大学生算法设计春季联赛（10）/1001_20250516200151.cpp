#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; scanf("%lld", &n);
    for (int i{}; i < n; ++ i) {
        int hh, mm, d;
        scanf("%lld:%lld %lld", &hh, &mm, &d);
        (hh += d + 96) %= 24;
        printf("%02lld:%02lld\n", hh, mm);
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; scanf("%lld", &_);
    while(_ --) solve();
    return 0;
}