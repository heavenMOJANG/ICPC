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
    string sv = "";
    vector<string> pc(n + 1, "");
    while (q --) {
        int op, p; cin >> op >> p;
        string s;
        if (op == 1) pc[p] = sv;
        if (op == 2) {
            cin >> s;
            pc[p].insert(pc[p].end(), s.begin(), s.end());
        }
        if (op == 3) sv = pc[p];
    }
    cout << sv << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}