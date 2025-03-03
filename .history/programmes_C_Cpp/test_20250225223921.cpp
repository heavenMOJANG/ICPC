#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("2.in", "w", stdout);
    int n = 100000;
    cout << n << endl;
    for (int i = 1; i <= n; ++ i) {
        cout << i;
        if (i == n) cout << endl;
        else cout << " ";
    }
    for (int i = 1; i < n; ++ i) cout << i << " " << i + 1 << endl;
    fclose(stdout);
    return 0;
}