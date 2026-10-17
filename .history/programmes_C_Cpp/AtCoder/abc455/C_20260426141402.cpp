#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, K; cin >> N >> K;
    map<int, int> A;
    for (int i{}; i < N; ++ i) {
        int x; cin >> x;
        A[x] ++;
    }
    vector<int> B;
    for (auto [k, x] : A) B.emplace_back(k * x);
    sort(B.begin(), B.end());
    while (!B.empty() && K) B.pop_back(), K --;
    int ans{};
    for (auto x : B) ans += x;
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}
