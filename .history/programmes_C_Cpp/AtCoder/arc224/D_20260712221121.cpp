#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, K; cin >> N >> K;
    if (N < 20 && K > (1ll << N)) { cout << "-1\n"; return; }
    vector<int> d(8, 0);
    int res{K}, f10{1};
    for (int i{1}; i <= 7; ++ i, f10 *= 10) {
        d[i] = min(res, i == 7 ? 1ll : f10 * 9);
        res -= d[i];
    }
    int ans{}, C{1}, cur{7};
    for (int i{}; i <= N && K; ++ i) {
        int tmp{min(C, K)};
        K -= tmp;
        while (tmp) {
            while (!d[cur]) cur --;
            int res{min(tmp, d[cur])};
            ans += res * cur * i;
            d[cur] -= res;
            tmp -= res;
        }
        if (i < N) C = min(2000000ll, C * (N - i) / (i + 1));
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}