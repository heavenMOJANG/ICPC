#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, Q; cin >> N >> Q;
    vector<int> A(N + 1);
    set<int> S;
    int ans{};
    while (Q --) {
        int op; cin >> op;
        if (op == 1) {
            int x; cin >> x;
            ans ^= A[x];
            A[x] ++;
            ans ^= A[x];
            S.insert(x);
        } else {
            for (auto it{S.begin()}; it != S.end();) {
                int x{*it};
                ans ^= A[x];
                A[x] --;
                ans ^= A[x];
                if (A[x] == 0) it = S.erase(it);
                else it ++;
            }
        }
        cout << ans << "\n";
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}