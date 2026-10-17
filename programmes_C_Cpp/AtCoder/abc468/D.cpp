#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string S; cin >> S;
    int N{(int)S.size()}, ans{};
    auto cal = [&](int l, int r) {
        int res{};
        while (l >= 0 && r < N) {
            if (S[l] != S[r]) res ++;
            if (res > 1) break;
            ans ++;
            l --, r ++;
        }
    };
    for (int i : views::iota(0, N)) {
        cal(i, i);
        cal(i, i + 1);
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