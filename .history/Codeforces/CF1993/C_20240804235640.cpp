#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++ i) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++ i) {
        b[i] = a[i] % (2 * k);
        if (b[i] < k) c[i] = b[i] + 2 * k;
        else c[i] = b[i];
    }
    {
        int minn = LLONG_MAX, maxn = 0;
        vector<pair<int,int>> t = b;

        for ()
    }
    {

    }
    cout << "-1\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}