#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
int lst[N];
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++ i) cin >> a[i];
    for (int i = 0; i < N; ++ i) lst[i] = -2;
    int l{}, ans{};
    for (int i = 0; i < n; ++ i) {
        if ((i - l) & 1) {
            if (lst[a[i]] == i - 1) l = lst[a[i]];
            else if (lst[a[i]] >= l) l = lst[a[i]] + 1;
        } else {
            if (a[i - 1] != a[i]) l = i;
        }
        ans = max(ans, i - l + 1);
        lst[a[i]] = i;
    }
    cout << ans / 2 * 2 << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}