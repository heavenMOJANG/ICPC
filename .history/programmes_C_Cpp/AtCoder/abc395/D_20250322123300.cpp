#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, q; cin >> n >> q;
    vector<int> h0(n), h1(n), p(n);
    iota(h0.begin(), h0.end(), 0);
    iota(h1.begin(), h1.end(), 0);
    iota(p.begin(), p.end(), 0);
    while (q --) {
        int op, a, b; cin >> op;
        switch (op) {
            case 2:
                cin >> a >> b;
                p[a - 1] = h1[b - 1];
                break;
            case 3:
                cin >> a >> b;
                swap(h1[a - 1], h1[b - 1]);
                swap(h0[h1[a - 1]], h0[h1[b - 1]]);
                break;
            case 4:
                cin >> a;
                cout << h0[p[a - 1]] + 1 << "\n";
                break;
        }
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}