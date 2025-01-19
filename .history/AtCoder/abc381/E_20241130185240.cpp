#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<int> id1, id2, ids;
    for (int i = 0; i < n; ++ i) (s[i] == '1' ? id1 : s[i] == '2' ? id2 : ids).emplace_back(i);
    
    while (q --) {
        int l, r; cin >> l >> r;
        l --;
        auto check = [&](int x) {
            if (!x) {
                int p = lower_bound(ids.begin(), ids.end(), l) - ids.begin();
                if (p >= ids.size()) return 0;
                return ids[p] < r;
            }
            int p = lower_bound(id1.begin(), id1.end(), l) - id1.begin();
            if (p + x - 1 >= id1.size()) return 0;
        };
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}