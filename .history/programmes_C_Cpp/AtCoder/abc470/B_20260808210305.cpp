#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N; cin >> N;
    map<int, int> mp;
    int maxn{};
    for (int i : ranges::iota_view(0, N)) {
        int C; cin >> C;
        mp[C] ++;
        maxn = max(maxn, mp[C]);
    }
    cout << N - maxn << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}