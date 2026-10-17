#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
void solve() {
    int N; cin >> N;
    vector<int> A(N + 1);
    for (int i : views::iota(1, N + 1)) cin >> A[i];
    vector<int> B(N + 1, 0), inv(N + 1, 0);
    B[1] = inv[1] = 1;
    for (int i : views:: iota(2, N + 1)) {
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
        B[i] = (B[i - 1] + inv[i]) % MOD;
    }
    int ans{};
    for (int i : views::iota(1, N + 1)) {
        int X{min(i, N - i + 1)};
        int t1{X * (B[N - X] - B[X] + MOD) % MOD};
        int t2{(N + 1) * (B[N] - B[N - X] + MOD) % MOD};
        (ans += (t1 + t2) % MOD * A[i]) %= MOD;
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}