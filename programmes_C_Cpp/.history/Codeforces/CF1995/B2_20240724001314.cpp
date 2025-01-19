#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
constexpr int inf = 0x7fffffff;
struct Node {int a,c;};
void solve() {
    int n, m; cin >> n >> m;
    vector<Node> f(n);
    for (int i = 0; i < n; ++ i) cin >> f[i].a;
    for (int i = 0; i < n; ++ i) cin >> f[i].c;
    sort(f.begin(), f.end(), [](const Node & x, const Node & y) {
        return x.a < y.a;
    });
    priority_queue<pii>pq;
    int maxn = 0;
    for (int i = 0; i < n; ++ i) {
        
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}