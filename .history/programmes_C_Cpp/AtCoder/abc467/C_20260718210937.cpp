#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, M; cin >> N >> M;
    vector<int> A(N);
    for (auto && x : A) cin >> x;
    vector<int> B(N - 1);
    for (auto && x : B) cin >> x;
    int ans0{}, ans1{}, tar0{}, tar1{1};
    for (int i{}; i < N; ++ i) {
        ans0 += A[i] != tar0;
        ans1 += A[i] != tar1;
        if (i < N - 1) tar0 ^= B[i], tar1 ^= B[i];
    }
    cout << min(ans0, ans1) << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}