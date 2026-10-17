#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, K; cin >> N >> K;
    vector<int> cnt(K + 1, 0);
    for (int i : views::iota(0, N)) { int A; cin >> A; cnt[A] ++; }
    int maxn{*max_element(cnt.begin() + 1, cnt.end())};
    int ans{};
    for (int i : views::iota(1,K + 1)) if (cnt[i] + 1 >= maxn) ans ++;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}