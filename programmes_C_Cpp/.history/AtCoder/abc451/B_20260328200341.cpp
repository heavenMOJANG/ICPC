#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, M; cin >> N >> M;
    vector<int> C(M + 1, 0);
    for (int i = 1; i <= n; ++ i) {
        int A, B; cin >> A >> B;
        C[B] ++;
        C[A] --;
    }
    for (int i = 1; i <= M; ++ i) cout << C[i] << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}