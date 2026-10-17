#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, X; cin >> N >> X;
    vector<int> B;
    int minn{LLONG_MAX};
    for (int i{}; i < N; ++ i) {
        int A; cin >> A;
        if (A < minn) B.emplace_back(A), minn = A;
    }
    int M{(int)B.size()};
    vector<int> dp(M);
    auto cal = [&](int L, int P) {
        int res{};
        while (L) {
            auto it{lower_bound(B.begin() + P, B.end(), L, greater<int>())};
            if (it == B.end()) { res ++; break; }
            int j{(int)(it - B.begin())};
            res += L / B[j] * dp[j];
            L %= B[j];
            P = j + 1;
        }
        return res;
    };
    for (int i{M - 1}; ~i; -- i) dp[i] = cal(B[i], i + 1);
    cout << cal(X + 1, 0) - 1 << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}