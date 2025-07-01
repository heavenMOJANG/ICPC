#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n, L, D; cin >> n >> L >> D;
    vector<int> a(n);
    for (int i = 0; i < n; ++ i) cin >> a[i];
    sort(a.begin() + 1, a.end());
    if (a[0] >= L) {
        int p = n;
        for (int i = n - 1; i; -- i) if (a[i] < L) {p = i; break;}
        if (p == n || p + 1 < 4) {cout << "No\n"; return;}
        if (max(a[0], a[p]) - min (a[0], a[1]) <= D) {cout << "No\n"; return;}
        cout << "Yes\n";
        return;
    }
    else {
        if (max(a[0], a[n - 1]) - min(a[0], a[1]) <= D) {cout << "No\n"; return;}
        if (a[2] >= L) {cout << "No\n"; return;}
        cout << "Yes\n";
        return;
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}