#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N; cin >> N;
    vector<int> P(N), Q(N), A(N);
    for (auto && x : P) cin >> x;
    for (auto && x : Q) cin >> x;
    iota(A.begin(), A.end(), 1);
    int ans{};
    do {
        if (P < A && A < Q) ans ++;
    } while (next_permutation(A.begin(), A.end()));
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}