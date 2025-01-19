#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, m; cin >> n >> m;
    struct Node {
        int l, r, type;
        Node() : l(0), r(0), type(0) {}
        Node(int l, int r, int type = 0) :
            l(l), r(r), type(type) {}
        bool operator < (const Node & x) const {return l == x.l ? r < x.r : l < x.l;}
        bool contain (const Node & x) const {return l <= x.l && r <= x.r;}  
    };
    vector<Node> a;
    for (int i = 0, b, e; i < n; ++ i) {
        cin >> b >> e;
        a.emplace_back(b, e, 0);
    }
    for (int i = 0, s, t; i < m; ++ i) {
        cin >> s >> t;
        a.emplace_back(s, t, 1);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); ++ i)
        if (a[i - 1].r > a[i].l) {cout << "No\n"; return;}
    if (a.front().type == 0) {cout << "No\n"; return;}
    Node tmp;
    for (auto cur : a) {
        if (cur.type) {
            auto [l, r, x] = cur;
            tmp = Node(r, r + 2 * (r - l));
        } else {
            if (!tmp.contain(cur)) {cout << "No\n"; return;}
        }
    }
    cout << "Yes\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}