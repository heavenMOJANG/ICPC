#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N; cin >> N;
    string S; cin >> S;
    vector<int> ans(N);
    int L{}, R{N - 1}, f{};
    for (int k{N - 1}; ~k; -- k) {
        int ff{(S[k] == 'o') ^ f};
        if (ff) ans[L ++] = k + 1;
        else ans[R --] = k + 1;
        if (S[k] != 'o') f ^= 1;
    }
    for (int i{0}; i < N; ++ i) cout << ans[i] << "\n"[i == N - 1];
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}