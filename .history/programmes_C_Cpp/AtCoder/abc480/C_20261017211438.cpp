#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, K, X; cin >> N >> K >> X;
    vector<int> A(N + 1);
    for (int i : views::iota(0, N + 1)) cin >> A[i];
    A[N] = X;
    ranges::sort(A);
    int ans{}, prev{-K};
    for (int cur : A) {
        if (cur > X) break;
        if (cur == prev) continue;
        ans += (cur - prev - 1) / K;
        prev = cur;
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