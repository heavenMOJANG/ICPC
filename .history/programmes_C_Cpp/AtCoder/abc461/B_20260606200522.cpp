#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N; cin >> N;
    vector<int> A(N), B(N);
    for (auto && x : A) cin >> x;
    for (auto && x : B) cin >> x;
    int f{1};
    for (int i{}; i < N; ++ i)
        if (B[A[i + 1]] != i + 1) f = 0;
    cout << (f ? "Yes" : "No") << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}