#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int A, B, X, Y; cin >> A >> B >> X >> Y;
    X = abs(X), Y = abs(Y);
    auto cal = [&](int X, int Y) -> int {
        int minn = min(X, Y), d{abs(X - Y)};
        int c1{min(A << 1, B << 1)}, c2{min({A + B, A << 2, B << 2})};
        return minn * c1 + d / 2 * c2;
    };
    if ((X + Y) & 1) {
        int ans = 2e18;
        ans = min({
            ans,
            A + cal(abs(X - 1), Y),
            A + cal(X + 1, Y),
            B + cal(X, abs(Y - 1)),
            B + cal(X, Y + 1)}
        );
        cout << ans << "\n";
    } else cout << cal(X, Y) << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}
