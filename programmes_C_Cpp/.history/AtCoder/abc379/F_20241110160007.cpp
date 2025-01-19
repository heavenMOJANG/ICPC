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
    SegmentTree(vector<int> & Info) : siz(Info.size()), t(siz << 2, 0) {
        void build (int p, int pl, int pr) {
            if (pl == pr) { t[p] = Info[pl]; return; }
        }
    }
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