#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    priority_queue<int> pq;
    for (auto && x : a) cin >> x, pq.push(x);
    if (k == 1) {cout << pq.top() << "\n"; return;}
    int minn = pq.top();
    while(!pq.empty()) {
        int x = pq.top();pq.pop();
        if (pq.empty()) {
            int res = 0;
            while (x) {
                x /= k;
                res ++;
            }
            minn = min(minn, res);
        } else {
            int res = 0;
            while (x > pq.top()) x /= k, res ++;
            minn = min(minn, res + pq.top());
            pq.push(x);
        }
    }
    cout << minn << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}