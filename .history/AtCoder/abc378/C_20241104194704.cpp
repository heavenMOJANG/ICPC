#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
int n, a[N], pos[N];
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    for (int i = 1; i <= n; ++ i) {
        if (!pos[a[i]]) cout << -1 << " \n"[i == n];
        else cout << pos[a[i]] << " \n"[i == n];
        pos[a[i]] = i;
    }
    return 0;
}