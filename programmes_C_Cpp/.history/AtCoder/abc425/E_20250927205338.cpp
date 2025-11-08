#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int MOD;
void solve() {
    auto qpow = [&](int a, int x) {
        int f = 1;
        while (x) {
            if (x & 1) f = f * a % MOD;
            a = a * a % MOD;
            x >>= 1;
        }
        return f;
    };
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _ >> MOD;
    while(_ --) solve();
    return 0;
}