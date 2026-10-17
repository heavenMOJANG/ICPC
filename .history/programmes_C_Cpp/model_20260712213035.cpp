#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
bool check(int x) {
    int l{-1};
    while (x) {
        int r{x % 10};
        if (r == 0 && l == 0) return true;
        l = r;
        x /= 10;
    }
    return false;
}
void solve() {
    int K; cin >> K;
    for (int i{1}; i <= 100; ++ i) {
        int N = i * K;
        if (check(N)) { cout << N << "\n"; return; }
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}