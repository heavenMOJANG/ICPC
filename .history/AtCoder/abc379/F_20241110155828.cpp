#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
class SegmentTree {
public:
    int siz{};
    vector<int> t;
    SegmentTree(vector & Info ) : siz(_siz), t(_siz << 2, 0) { build(); }
    void build () { build (1, 1, siz); }
};
void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    while (q --) {
        int l, r; cin >> l >> r;
        if (a[l] < a[r]) { cout << "0\n"; continue; }

    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}