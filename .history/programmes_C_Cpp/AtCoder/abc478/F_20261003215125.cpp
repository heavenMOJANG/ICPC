#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int MOD = 998244353;
void solve() {
    int N; cin >> N;
    vector<int> Q(N);
    for (auto && x : Q) cin >> x;
    vector<int> stk;
    int ans{1};
    stk.emplace_back(0);
    for (int i : views::iota(1, N)) {
        while (!stk.empty() && Q[stk.back()] < Q[i]) stk.pop_back();
        int mul{};
        mul = stk.empty() ? i : i - stk.back();
        (ans *= mul) %= MOD;
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}