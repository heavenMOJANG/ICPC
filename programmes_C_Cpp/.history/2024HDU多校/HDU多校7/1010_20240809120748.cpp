#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, x, k; cin >> n >> x >> k;
    vector<int> a(n + 1);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
        if (i <= k) pq.push(a[i]);
    }
    if (k >= n) {cout << n << "\n"; return;}
    
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}