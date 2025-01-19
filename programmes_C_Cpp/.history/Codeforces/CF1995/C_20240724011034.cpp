#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n),cnt(n, 0);
    for (int i = 0; i < n; ++ i) cin >> a[i];
    for (int i = 1; i < n; ++ i) {
        if (a[i] < a[i - 1]) {
            if (a[i] == 1) {
                cout << "-1\n";
                return;
            } else {
                int res = 0, tmp = a[i];
                while (tmp < a[i - 1]) {
                    tmp = tmp * tmp;
                    res ++;
                }
                cnt[i] = cnt[i - 1] + res;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < n; ++ i) sum += cnt[i];
    cout << sum << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}