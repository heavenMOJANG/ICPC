#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N; cin >> N;
    int n = floor(log2(N)) + 3;
    vector A(n, vector<int> (n, 0));
    for (int i{}; i < n; ++ i) A[i][i] = 1;
    for (int i{}; i + 1 < n; ++ i) A[i][i + 1] = 1;
    for (int i{}; i <= n - 2; ++ i)
        if ((N >> i) & 1) A[n - 1][n - 2 - i] = 1;
    cout << n << "\n";
    for (int i{}; i < n; ++ i)
        for (int j{}; j < n; ++ j) cout << A[i][j] << " \n"[j == n - 1];
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}