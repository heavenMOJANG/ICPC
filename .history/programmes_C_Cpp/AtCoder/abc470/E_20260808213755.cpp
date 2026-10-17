#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, L; cin >> N >> L;
    long double ans{};
    for (int i : views::iota(0, N)) {
        int x; cin >> x;
        ans += x;
    }
    vector dp(210, vector<vector<long double>> (210, vector<long double>(210, 0.0l)));
    for (int l : views::iota(1, L + 1)) {
        for (int j : views::iota(0, N + 1)) dp[l][0][j] = j;
        for (int i : views::iota(1, N + 1))
            for (int j : views::iota(0, N - i + 1)) {
                long double M{2.0l * i + j}, res{};
                if (j) res += j / M * (1 + dp[l][i][j - 1]);
                long double tmp{};
                tmp += (1 + dp[l][i - 1][j]) / (M - 1);
                if (i >= 2) tmp += 2.0l * (i - 1) / (M - 1) * dp[l - 1][i - 2][j + 2];
                if (j && l >= 2) tmp += j / (M - 1) * (1 + dp[l - 1][i - 1][j]);
                res += 2.0l * i / M * tmp;
                dp[l][i][j] = res;
            }
    }
    ans *= dp[L][N][0] / N;
    cout << fixed << setprecision(10) << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}