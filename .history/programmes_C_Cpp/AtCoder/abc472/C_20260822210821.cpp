#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, M, K; cin >> N >> M >> K;
    vector<int> A(N);
    for (auto && x : A) cin >> x;
    vector<int> B(N, 0);
    int sum{};
    for (int i : views::iota(0, N)) {
        if (i - M >= 0) sum -= B[i - M];
        if (sum + A[i] <= K) {
            cout << "Yes\n";
            B[i] = A[i];
            sum += A[i];
        } else cout << "No\n";
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}