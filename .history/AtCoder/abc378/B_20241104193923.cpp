#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 110;
int n, q, a[N], b[N], t, d;
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> a[i] >> b[i];
    cin >> q;
    while (q --) {
        cin >> t >> d;
        if (d % a[t] == b[t]) cout << d << "\n";
        else cout << (d % a[t] < b[t] ? d / a[t] * a[t] + b[t] : d / a[t] * (a[t] + 1) + b[t]) << "\n";
    }
    return 0;
}