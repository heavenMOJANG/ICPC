#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int X; cin >> X;
    int ans{};
    auto check = [&](int A, int D, int N) {
        __int128 res{1};
        for (int i : views::iota(0, N)) {
            res *= A + i * D;
            if (res > X) return false;
        }
        return true;
    };
    for (int A{1}; A * A * A <= X; ++ A)
        for (int N{3}; check(A, 1, N); N ++) {
            int L{1}, R{(int)1e9};
            while (L + 1 < R) {
                int mid{L + R >> 1};
                if (check(A, mid, N)) L = mid;
                else R = mid;
            }
            ans += L;
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