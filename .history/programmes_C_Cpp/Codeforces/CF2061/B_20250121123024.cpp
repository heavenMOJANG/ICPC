#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    int maxL = -1;
    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
        if (mp[a[i]] && a[i] > maxL) maxL = a[i];
        mp[a[i]] ++;
    }
    int rst = 2;
    vector<int> b;
    for (int i = 0; i < n; ++ i) {
        if (rst && a[i] == maxL) rst --;
        else b.emplace_back(a[i]);
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < b.size() - 1; ++ i)
        if (b[i] + 2 * maxL > b[i + 1]) { cout << maxL << " " << maxL << " " << b[i] << " " << b[i + 1] << "\n"; return; }
    cout << "-1\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}