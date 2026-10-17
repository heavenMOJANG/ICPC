#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, Q; cin >> N >> Q;
    vector<int> A(N + 1, 0);
    int MAXH = N + Q + 5;
    vector<int> B(MAXH, 0), C(MAXH, 0);
    B[0] = C[0] = N;
    int cnt{};
    while (Q --) {
        int op{}; cin >> op;
        if (op == 1) {
            int x; cin >> x;
            int h = A[x];
            B[h] --;
            B[h + 1] ++;
            C[h + 1] ++;
            A[x] ++;
            while (B[cnt] == 0) cnt ++;
        } else {
            int y; cin >> y;
            int ans = y + cnt;
            if (ans >= MAXH) cout << "0\n";
            else cout << C[ans] << "\n";
        }
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}
