#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Node {
    int prev;
    string s;
};
void solve() {
    int n, q; cin >> n >> q;
    vector<Node> v;
    vector<int> pc(n + 1, 0);
    int sv{};
    v.emplace_back(0, "");
    while (q --) {
        int op, p; cin >> op >> p;
        if (op == 1) pc[p] = sv;
        if (op == 2) {
            string s; cin >> s;
            v.emplace_back(pc[p], s);
            pc[p] = v.size() - 1;
        }
        if (op == 3) sv = pc[p];
    }
    reverse(v.begin(), v.end());
    for (auto [id, s] : v) cout << s;
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}