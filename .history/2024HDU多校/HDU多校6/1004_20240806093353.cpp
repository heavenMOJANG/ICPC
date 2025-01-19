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
    int r = 0;
    for (int i = 0; i < n; ++ i) {
        if (cls[i].first <= r) {cout << "No\n"; return;}
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}