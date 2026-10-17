#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N; cin >> N;
    vector A(N + 1, vector<int>(1, 0));
    for (int i = 1; i <= N; ++ i) {
        int L; cin >> L;
        for (int j = 1; j <= L; ++ j) {
            int x; cin >> x;
            A[i].emplace_back(x);
        }
    }
    int X, Y; cin >> X >> Y;
    cout << A[X][Y] << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}
