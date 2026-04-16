#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, K; cin >> N >> K;
    vector<int> a(N);
    for (auto && x : a) {
        cin >> x;
        x %= K;
    }
    sort(a.begin(), a.end());
    int maxn = a[0] - a[N - 1] + K;
    for (int i = 1; i < N; ++ i) maxn = max(maxn, a[i] - a[i - 1]);
    cout << maxn << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}