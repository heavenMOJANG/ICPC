#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int>> a, b;
    priority_queue<int, vector<int>, less<int>> c;
    for (int i = 0, x; i < n; ++ i) {
        cin >> x;
        if (x & 1) a.push(x);
        else b.push(x), c.push(x);
    }
    if (a.size() == 0 || b.size() == 0) {cout << "0\n"; return;}
    if (a.top() > b.top()) cout << b.size() << "\n";
    else {
        
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}