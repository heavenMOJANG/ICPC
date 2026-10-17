#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N; cin >> N;
    vector<int> freq(101, 0);
    for (int i : views::iota(0, N)) {
        int x; cin >> x;
        freq[x] ++;
    }
    int ans{};
    for (int i : views::iota(1, 101)) ans += freq[i] % 2 * i;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}