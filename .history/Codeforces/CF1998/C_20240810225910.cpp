#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Node {int val, id;};
void solve() {
    int n, k; cin >> n >> k;
    vector<Node> a(n + 1);
    vector<int> b(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> a[i].val, a[i].id = i;
    for (int i = 1; i <= n; ++ i) cin >> b[i];
    sort(a.begin() + 1, a.begin() + 1 + n, [](const Node & x, const Node & y) {return x.val < y.val;});
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}