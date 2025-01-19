#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n), b;
    for (int i = 0; i < n; ++ i) cin >> a[i];
    b = a;
    sort(b.begin(), b.end());
    priority_queue<int> q0, q1, q2;
    for (int i = 0; i < n; ++ i)
        if (a[i] != b[i]) {
            if (a[i] == 0) q0.push(i);
            if (a[i] == 1) q1.push(i);
            if (a[i] == 2) q2.push(i);
        }
    while (q0.size() + q1.size() + q2.size() >= 2) {
        
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}