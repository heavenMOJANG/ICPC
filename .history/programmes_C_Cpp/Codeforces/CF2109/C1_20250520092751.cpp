#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int query(int op, int x = -1) {
    switch (op) {
        case 1: cout << "add " << x << endl; break;
        case 2: cout << "mul " << x << endl; break;
        case 3: cout << "div " << x << endl; break;
        case 4: cout << "digit " << x << endl; break;
        case 5: cout << "!" << endl; break;
    }
    int res; cin >> res;
    return res;
}
void solve() {
    int n; cin >> n;
    query(4); query(4);
    int l = 1, r = 16;
    while (l < r) {
        int mid = l + r >> 1;
        if (query(1, -mid)) r -= mid;
        else r = mid;
    }
    query(2, n);
    query(5);
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}