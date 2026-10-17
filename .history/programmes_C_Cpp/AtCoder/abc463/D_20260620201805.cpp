#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Node { int L, R; };
void solve() {
    int N, K; cin >> N >> K;
    vector<Node> A(N);
    for (auto && [l, r] : A) cin >> l >> r;
    ranges::sort(A, [](const Node& x, const Node& y) {
        return x.R != y.R ? x.R < y.R :x.L < y.L;
    });
    auto check = [&](int X) -> bool {
        int res{}, lst{};
        for (const auto& [L, R] : A) {
            if (!res) lst = R, res ++;
            else if (L - lst >= X) lst = R, res ++;
            if (res >= K) return true;
        }
        return false;
    };
    int l{1}, r{(int)1e9 + 7}, ans{-1};
    while (l <= r) {
        int mid = l + (r - l) / 2;
        check(mid) ? ans = mid, l = mid + 1 : r = mid - 1;
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