#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, K; cin >> N >> K;
    vector<int> A(N);
    for (int i{}; i < N; ++ i) cin >> A[i];
    auto check = [&](int x) {
        int res{};
        for (int i{}; i < N; ++ i)
            if (A[i] < x) {
                int d = x - A[i];
                int cnt = i + 1, need = (d + cnt - 1) / cnt;
                res += need;
                if (res > K) return false;
            }
        return res <= K;
    };
    int l{}, r = 4e18, ans{};
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
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
