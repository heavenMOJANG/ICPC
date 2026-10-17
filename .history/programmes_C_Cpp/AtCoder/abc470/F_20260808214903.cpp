#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#include <atcoder/all>
#define int long long
using namespace std;
using namespace atcoder;
using mint = modint998244353;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, M; cin >> N >> M;
    string S; cin >> S;
    dsu d(N);
    while (M --) {
        int A, B; cin >> A >> B;
        d.merge(A --, B --);
    }
    vector<mint> fac(N + 1, 1), inv(N + 1, 1);
    for (int i : views::iota(1, N + 1)) fac[i] = fac[i - 1] * i;
    inv[N] = fac[N].inv();
    for (int i{N}; i; i --) inv[i - 1] = inv[i] * i;
    mint ans{1};
    bool same{};
    for (auto &v : d.groups()) {
        array<int, 26> cnt{};
        for (int i : v) cnt[S[i] - 'a'] ++;
        ans *= fac[v.size()];
        for (int x : cnt) {
            ans *= inv[x];
            if (x > 1) same = true;
        }
    }
    if (!same) ans /= 2;
    cout << ans.val() << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}