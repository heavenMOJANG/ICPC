#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, K; cin >> N >> K;
    vector<int> A(N);
    for (auto && x : A) cin >> x;
    int ans{};
    for (int x : A) if (x == K) ans ++;
    for (int i : views::iota(0, N - 1))
        if (A[i] < K && K < A[i + 1] || A[i + 1] < K && K < A[i]) ans ++;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}