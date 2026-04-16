#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, M; cin >> N >> M;
    vector<int> a(N + 1), cnt(M + 1, 0);
    for (int i = 1; i <= N; ++ i) cin >> a[i], cnt[a[i]] ++;
    vector<pair<int, int>> b;
    for (int v = 1; v <= M; ++ v) b.emplace_back(cnt[v], v);
    sort(v.begin(), v.end());
    vector<int> ord;
    for (auto [fi, se] : b) ord.emplace_back(se);
    int Q; cin >> Q;
    while (Q --) {
        int X; cin >> X;
        if (X <= N) cout << A[X] << "\n";
        else cout << ord[(X - N + 1) % M] << "\n";
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}