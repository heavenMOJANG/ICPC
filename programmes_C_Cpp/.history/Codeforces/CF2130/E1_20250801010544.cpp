#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int ask(const vector<int>& q) {
    cout << "? " << q.size();
    for (int x : q) cout << " " << x;
    cout << endl;
    int res; cin >> res;
    return res;
}
void solve() {
    
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}