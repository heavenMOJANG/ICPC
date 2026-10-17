#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, M; cin >> N >> M;
    vector<int> A(N), B(M);
    for (auto && x : A) cin >> x;
    for (auto && x : B) cin >> x;
    ranges::sort(A);
    ranges::sort(B);
    int ans{}, pa{}, pb{};
    while (pa < N && pb < M) {
        if (B[pb] <= 2 * A[pa]) ans ++, pa ++, pb ++;
        else pa ++;
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
