#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, K; cin >> N >> K;
    vector<int> A(N + 1);
    auto dfs = [&](auto self, int i, int x) {
        if (i == N) {
            if (x % N == 0) {
                A[N] = x / N;
                for (int j : views::iota(1, N + 1)) cout << A[j] << " \n"[j == N];
            }
            return;
        }
        for (int j{}; i * j <= x; ++ j) {
            A[i] = j;
            self(self, i + 1, x - i * j);
        }
    };
    dfs(1, K);
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}