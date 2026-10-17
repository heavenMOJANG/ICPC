#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N; cin >> N;
    for (int i : views::iota(0, N)) {
        int A; cin >> A;
        int k{A / 1000 + 1}, r{k * 1000 - A};
        int ans{};
        ans += r / 100; r %= 100;
        ans += r / 10; r %= 10;
        ans += r;
        cout << ans << " \n"[i == N - 1];
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}