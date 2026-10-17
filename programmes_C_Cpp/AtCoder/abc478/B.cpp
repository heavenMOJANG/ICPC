#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, V; cin >> N >> V;
    vector<int> W(N);
    for (auto && x : W) cin >> x;
    int maxn{};
    for (int i : views::iota(0, N - 2))
        for (int j : views::iota(i + 1, N - 1))
            for (int k : views::iota(j + 1, N))
                if (i + j + k + 3 <= V) maxn = max(maxn, W[i] + W[j] + W[k]);
    cout << maxn << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}