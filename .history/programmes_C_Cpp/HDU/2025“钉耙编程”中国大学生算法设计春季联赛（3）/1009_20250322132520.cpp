#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, q; cin >> n >> q;
    vector<int> f(n + 1), fa(n + 1), h0(n + 1), h1(n + 1);
    iota(f.begin(), f.end(), 0);
    iota(fa.begin(), fa.end(), 0);
    iota(h0.begin(), h0.end(), 0);
    iota(h1.begin(), h1.end(), 0);
    while (q --) {
        int op, a, b; cin >> op >> a;
        switch (op) {
            case 1: cin >> b; fa[h1[b]] = h1[a]; break;
            case 2: cin >> b; fa[a] = h1[b]; break;
            case 3: cin >> b; swap(h1[a], h1[b]); swap(h0[h1[a]], h0[h1[b]]); break;
            case 4: cout << h0[fa[a]] << "\n"; break;
        }
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}