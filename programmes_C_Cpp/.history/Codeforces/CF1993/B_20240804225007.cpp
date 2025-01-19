#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    priority_queue<int> a;
    priority_queue<int, vector<int>, less<int>> b;
    for (int i = 0, x; i < n; ++ i) {
        cin >> x;
        if (x & 1) a.push(x);
        else b.push(x);
    }
    if (a.size() == 0 || b.size() == 0) {cout << "0\n"; return;}
    int ans = 0;
    while(!b.empty()) {
        int u = a.top(); a.pop();
        int v = b.top(); b.pop();
        if (u > v) a.push(u + v), ans ++;
        else a.push(u + 2 * v), ans += 2;
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}