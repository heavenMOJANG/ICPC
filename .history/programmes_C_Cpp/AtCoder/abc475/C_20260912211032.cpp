#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, S, L; cin >> N >> S >> L;
    vector<int> pre(N + 1, 0);
    for (int i : views::iota(1, N)) {
        int A; cin >> A;
        pre[i + 1] = pre[i] + A;
    }
    auto cal = [&](int l, int r) {
        int x{pre[S] - pre[l]}, y{pre[r] - pre[S]};
        return x + y + min(x, y);
    };
    int ans{1}, r{S};
    for (int l : views::iota(1, S + 1)) {
        if (cal(l, S) > L) continue;
        while (r + 1 <= N && cal(l, r + 1) <= L) r ++;
        ans = max(ans, r - l + 1);
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