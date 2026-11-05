#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, M; cin >> N >> M;
    vector<int> A(N);
    for (auto && x : A) cin >> x;
    int K{accumulate(A.begin(), A.end(), 0ll) / M};
    int n{1ll << N};
    vector<int> sum(n), dp(n);
    for (int s : views::iota(1, n)) {
        int i{countr_zero((unsigned)s)};
        sum[s] = sum[s ^ (1ll << i)] + A[i];
        for (int t{s}; t; t &= t - 1) {
            int j{countr_zero((unsigned)t)};
            dp[s] = max(dp[s], dp[s ^ (1ll << j)]);
        }
        dp[s] += (sum[s] % K == 0);
    }
    cout << M - dp[n - 1] << "\n";
    return;
}
/*
　グラフ上の最長路として解答する。
　まず、1人分のケーキの大きさをdelta(A)//Mとする。
　次に、集合S->{1,...,N}とし、各頂点をビット集合で表す。
　まだ選んでいないケーキiを追加する有向辺S->S+{i}を張る。
　そして、辺の重みは、追加後のケーキの総和がKの倍数なら1、そうでなければ0とする。
　各辺でケーキの個数が1増えるため、このグラフはDAGである。
　よって、空集合から全集合への最長路の重みをCとすると、答えはM-Cとなる。
*/
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}