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
        if (max(a[0], a[n - 1]) - min(a[0], a[1]) <= D) {cout << "No\n"; return;}

    }
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