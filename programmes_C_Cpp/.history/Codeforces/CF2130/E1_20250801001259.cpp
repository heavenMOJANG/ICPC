#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int ask(const vector<int>& v) {
    cout << "? " << v.size() << endl;
    for (int x : v) cout << x << " ";
    cout << endl;
    int res; cin >> res;
    return res;
}
void solve() {
    int n; cin >> n;
    int l = 1, r = n, p = n;
    while (l <= r) {
        int mid = l + r >> 1;
        vector<int> q(mid);
        iota(q.begin(), q.end(), 1);
        int res = ask(q);
        if (res > 0) p = mid, r = mid - 1;
        else l = mid + 1;
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}