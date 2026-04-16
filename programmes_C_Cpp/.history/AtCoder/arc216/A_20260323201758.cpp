#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N; cin >> N;
    string A, B; cin >> A >> B;
    if (A.front() != B.front() || A.back() != B.back()) { cout << "-1\n"; return; }
    vector<int> pa, pb;
    for (int i = 1; i <= N; ++ i) {
        int fa = (A[i - 1] != A[i]);
        if (i % 2 == 0) fa ^= 1;
        int fb = (B[i - 1] != B[i]);
        if (i % 2 == 0) fb ^= 1;
        if (fa) pa.emplace_back(i);
        if (fb) pb.emplace_back(i);
    }
    if (pa.size() != pb.size()) { cout << "-1\n"; return; }
    int ans{};
    for (int i{}; i < pa.size(); ++ i) ans += abs(pa[i] - pb[i]);
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}