#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N; cin >> N;
    vector<int> A(N + 1);
    for (int i : views::iota(1, N + 1)) cin >> A[i];
    int ans{};
    for (int i : views::iota(1, N - 1)) if (A[i] < A[i + 1] && A[i + 1] > A[i + 2]) ans ++;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}